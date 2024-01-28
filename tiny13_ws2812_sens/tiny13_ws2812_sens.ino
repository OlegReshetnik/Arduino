//#define F_CPU 9600000UL
#include <avr/io.h>
#include <util/delay.h>

/* RES           ____
(D5/A0) PB5    1|    |8    VCC
(D3/A3) PB3    2|    |7    PB2 (D2/A1) SCK
(D4/A2) PB4    3|    |6    PB1 (D1/PWM) MISO
		GND    4|____|5    PB0 (D0/PWM) MOSI */

#define NUM_LEDS 12    // количество светодиодов
#define NUM_BYTES (NUM_LEDS * 3)

// Настройки порта ленты
#define WS2812_PIN 3             // пин подключения
#define WS2812_PORT PORTB    // порт подключения
#define WS2812_DDR DDRB        // DDR порт подключения

uint8_t leds[NUM_BYTES];

void wsDel(uint8_t del) { while (del--) { _delay_ms(1); } }

#define TOUCH_BIT			4 // PB4, A2
#define TOUCH_ADC			2 // PB4, A2

#define TOUCH_THRESHOLD		200
#define TOUCH_SAMPLES		32

uint8_t k;

uint16_t TouchRead(void) {
	uint16_t val = 0;
	k = TOUCH_SAMPLES;
	while (k--) {
    ADMUX = TOUCH_ADC;                // Select ADC channel
    DDRB |= (1 << TOUCH_BIT);          // Discharge touchpad
    PORTB &= ~(1 << TOUCH_BIT);

    ADCSRA |= (1 << ADEN);              // Enable ADC & discharge S/H cap
    _delay_us(1);                       // Sample and hold RC time
    ADCSRA = 0;                         // ADC off
    PORTB |= (1 << TOUCH_BIT);         // Charge touchpad

    DDRB  &= ~(1 << TOUCH_BIT);        // Input mode
    PORTB &= ~(1 << TOUCH_BIT);        // Pullup off

    // Enable ADC with /16 prescaler, equalize S/H cap charge
    ADCSRA = (1 << ADPS2) | (0 << ADPS1) | (0 << ADPS0) | (1 << ADEN);
    _delay_us(1);                       // Sample and hold RC time

    ADCSRA |= (1 << ADSC);              // Start ADC conversion
    while (bit_is_set(ADCSRA, ADSC));   // Wait for conversion to complete
    val += ADCW;
    ADCSRA = 0;                         // ADC off
	}

	return val;
}

void inline wsSend(void) {
	uint8_t *data = (uint8_t *)leds;
	uint8_t curbyte, ctr;
	uint8_t masklo = (~(1 << WS2812_PIN)) & WS2812_PORT;
	uint8_t maskhi = (1 << WS2812_PIN) | WS2812_PORT;

	k = NUM_BYTES;
	WS2812_DDR |= (1 << WS2812_PIN);    // Enable output

	while (k--) {
	curbyte = *data++;
	asm volatile(
	    "	ldi %0,8 \n\t"    // 1 такт, что = 1/F_CPU = 1/9600000 = 0,10417 мкс
	    "loop%=: \n\t"
	    "	out %2,%3 \n\t"     // 1 > 1
	    "	nop \n\t"                 // 1 > 2
	    "	sbrs %1,7 \n\t"     // если бит 7 в 1 то 2 такта, иначе 1
	    "	out %2,%4 \n\t"     // 1 - оба в любом случае 2 такта > 4
	    "	lsl %1 \n\t"            // 1 > 5
	    "	nop \n\t"                 // 1 > 6
	    "	nop \n\t"                 // 1 > 7
	    "	out %2,%4 \n\t"     // 1 > 8
	    "	nop \n\t"                 // 1 > 9
	    "	nop \n\t"                 // 1 > 10
	    "	dec %0 \n\t"            // 1 > 11
	    "	brne loop%=\n\t"    // 1 - конец > 12, 2- переход > 13
	    : "=&d"(ctr)
	    : "r"(curbyte), "I"(_SFR_IO_ADDR(WS2812_PORT)), "r"(maskhi), "r"(masklo));
	}
	//_delay_us(50); // сброс 50 мкс
}

uint8_t wsFade(uint8_t val, uint8_t fade) { return (((uint16_t)val * (uint16_t)fade) + 255) >> 8; }

uint8_t wsGamma(uint8_t val) { return wsFade(val, val); }

void setRGB(uint8_t r, uint8_t g, uint8_t b, uint8_t idx, uint8_t fade) {
	uint8_t *grb = &leds[idx * 3];
	*grb++ = wsGamma(wsFade(g, fade));
	*grb++ = wsGamma(wsFade(r, fade));
	*grb++ = wsGamma(wsFade(b, fade));
}

uint8_t shift, r, g, b;
void wsH2RGB(uint8_t color, uint8_t idx, uint8_t fade) {
	if (color > 170) {
		shift = (color - 170) * 3;
		r = shift; g = 0;
		b = 255 - shift; }
	else if (color > 85) {
		shift = (color - 85) * 3;
		r = 0;
		g = 255 - shift;
		b = shift;
	} else {
		shift = color * 3;
		r = 255 - shift;
		g = shift;
		b = 0;
	}
	setRGB(r, g, b, idx, fade);
}

uint8_t hue = 0, fade = 127, inc = 1;

void addFade(void) {
	fade += inc;
	if (fade > 254) { inc = 255; }
	else if (fade < 60) { inc = 1; }
}

// ****************************** ЦВЕТА ******************************
void wsColors(void) {
	for (k = 0; k < NUM_LEDS; k++) { wsH2RGB(hue, k, fade); }
	//hue += 3;
	addFade();
}

uint16_t sens;
uint8_t scnt = 0;

uint8_t isTouch(void) {
  if (scnt) { scnt--; return 0; }
  if (TouchRead()>(sens+TOUCH_THRESHOLD)) { scnt = 10; return 1; }
  else if (scnt) { scnt--; }
  return 0;
}

__attribute__((section(".init9"))) int main(void) {
	sens = TouchRead();
	
	while (1) {
		if (isTouch()) { hue += 21; }
		wsColors();
		wsSend();
		wsDel(50);
	}
}
