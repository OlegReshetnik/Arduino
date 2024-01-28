//#define F_CPU 9600000 //fuse LOW=0x7a
/* RES			 ____
(D5/A0) PB5	   1|	 |8	   VCC
(D3/A3) PB3	   2|	 |7	   PB2 (D2/A1) SCK
(D4/A2) PB4	   3|	 |6	   PB1 (D1/PWM) MISO
		GND	   4|____|5	   PB0 (D0/PWM) MOSI */

#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

//--------------------------------------- WS UTILITY --------------------------------------
#define WS_RAND_ADC 2  // ADC2 - PB4 для analogRead из Пустоты

void wsDelay(uint8_t del) {
	while (del--) { _delay_ms(1); }
}

uint8_t wsFade(uint8_t val, uint8_t fade) {
	return (((uint16_t)val * (uint16_t)fade) + 255) >> 8;
}

uint8_t wsGamma(uint8_t val) {
	return wsFade(val, val);
}

uint16_t __wsRandValue;

void wsRandSeed(void) {
	uint8_t cnt = 10;
	while (cnt--) {
		ADMUX = (ADMUX & 0xFC) | WS_RAND_ADC;
		ADCSRA = (1 << ADEN) | (1 << ADSC);	 // Prescaler to F_CPU / 2
		while (ADCSRA & (1 << ADSC)); // Wait for conversion
	__wsRandValue += ADCW;	// randomSeed((uint16_t)analogRead(A1));
	ADCSRA = 0;			// turn off ADC
	}
}

uint16_t wsRand16(void) {
	__wsRandValue *= (uint16_t)2053;
	__wsRandValue += (uint16_t)13849;
	return __wsRandValue;
}

uint8_t wsRand8(void) {
	wsRand16();
	return (uint8_t)(((uint8_t)(__wsRandValue & 0xFF)) + ((uint8_t)(__wsRandValue >> 8)));
}

uint8_t wsRand8_1(uint8_t max) {
	return ((wsRand8() * max + max) >> 8);
}

uint8_t wsRand8_2(uint8_t min, uint8_t max) {
	return (wsRand8_1(max - min) + min);
}

uint8_t wsSub(uint8_t i, uint8_t j) {
	int16_t t = i - j;
	if (t < 0) t = 0;
	return t;
}

uint8_t wsAdd(uint8_t i, uint8_t j) {
	uint16_t t = i + j;
	if (t > 255) t = 255;
	return t;
}
//------------------------------------- END WS UTILITY ------------------------------------

//------------------------------------------ LED ------------------------------------------
#define LED_PIN 0  // PWM pin PB0

void ledInit(void) {
	DDRB |= (1 << LED_PIN);								  // pin to Output
	TCCR0A |= (1 << COM0A1) | (1 << WGM01) | (1 << WGM00);  //  Clear OC0A on Compare Match, set OC0A at TOP(0xFF), Fast PWM
	TCCR0B = (1 << CS01);									  // clkI/O/8, PWM frequency = (F_CPU/256) / 8 = 4687,5
}

void ledOut(uint8_t val) {
	OCR0A = wsFade(val, val);
}


void ledPulse(uint8_t lo, uint8_t hi, uint8_t del) {
	uint8_t bright = lo;

	while (bright != hi) {
		ledOut(bright++);
		wsDelay(del);
	}
	while (bright != lo) {
		ledOut(bright--);
		wsDelay(del);
	}
}
//---------------------------------------- END LED ----------------------------------------

#define RND_REPEAT_MIN 1
#define RND_REPEAT_MAX 3

#define RND_LO_MIN 1
#define RND_LO_MAX 150

#define RND_HI_MIN 152
#define RND_HI_MAX 255

#define RND_DEL_MIN 2
#define RND_DEL_MAX 25

int main() {
	wsRandSeed();
	ledInit();

	for (;;) {
		uint8_t repeat = wsRand8_2(RND_REPEAT_MIN, RND_REPEAT_MAX);
		uint8_t lo = wsRand8_2(RND_LO_MIN, RND_LO_MAX);
		uint8_t hi = wsRand8_2(RND_HI_MIN, RND_HI_MAX);
		uint8_t del = wsRand8_2(RND_DEL_MIN, RND_DEL_MAX);

	while (repeat--) { ledPulse(lo, hi, del); }
	}
}
