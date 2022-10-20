// atmega serial lib
#pragma once

#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>

#if !defined(UART_SPEED)
	#define UART_SPEED		4800 // serial boudrate
#endif

#if !defined(SPEED_ACCURACY)
	#define SPEED_ACCURACY	2 // speed tolerance 2%
#endif

#if !defined(UART_TIMEOUT)
	#define UART_TIMEOUT	(1000000UL) // 1 seconds
#endif

#define UART_DS				(1000000UL/(UART_SPEED*4UL)) // 1/4 bit delay

#ifndef F_CPU
	#error "uart.h requires F_CPU to be defined!"
#endif
#if !(F_CPU)
	#error "F_CPU must be a constant value!"
#endif

#define UBRR_VALUE (((F_CPU)+8UL*(UART_SPEED))/(16UL*(UART_SPEED))-1UL)

#if 100*(F_CPU) > (16*((UBRR_VALUE)+1))*(100*(UART_SPEED)+(UART_SPEED)*(SPEED_ACCURACY))
	#define USE_2X	1
#elif 100*(F_CPU) < (16*((UBRR_VALUE)+1))*(100*(UART_SPEED)-(UART_SPEED)*(SPEED_ACCURACY))
	#define USE_2X	1
#else
	#define USE_2X	0
#endif

#if USE_2X // U2X required, recalculate
	#undef UBRR_VALUE
	#define UBRR_VALUE (((F_CPU)+4UL*(UART_SPEED))/(8UL*(UART_SPEED))-1UL)

	#if 100*(F_CPU) > (8*((UBRR_VALUE)+1))*(100*(UART_SPEED)+(UART_SPEED)*(SPEED_ACCURACY))
		#warning "Baud rate achieved is higher than allowed!"
	#endif

	#if 100*(F_CPU) < (8*((UBRR_VALUE)+1))*(100*(UART_SPEED)-(UART_SPEED)*(SPEED_ACCURACY))
		#warning "Baud rate achieved is lower than allowed!"
	#endif
#endif // USE_U2X

#if UBRR_VALUE >= (1<<12)
	#warning "UBRR value overflow!!!"
#endif

#define UBRRH_VALUE (UBRR_VALUE >> 8)
#define UBRRL_VALUE (UBRR_VALUE & 0xff)

#if defined(UBRR0H)
	#define UBRRH	UBRR0H
	#define UBRRL	UBRR0L
	#define UCSRA 	UCSR0A
	#define UCSRB 	UCSR0B
	#define UCSRC 	UCSR0C
	#define UDR		UDR0
	#define RXC		RXC0
	#define UDRE	UDRE0
	#define RXEN	RXEN0
	#define TXEN	TXEN0
	#define U2X		U2X0
#endif

#define uartRxReady()	(UCSRA&(1<<RXC))	// has recv byte?

uint8_t uartRx(void) { while (uartRxReady() == 0); return UDR; }

void uartFlushRx(void) { while (uartRxReady()) { uartRx(); } }

bool uartWaitRx(void) {
	uint16_t timeout = UART_TIMEOUT/UART_DS;
	while (timeout--) {
		if (uartRxReady()) { return true; }
		else { _delay_us(UART_DS); }
	}
	return false;
}

#define	uartTxReady()		(UCSRA&(1<<UDRE))	// want trans byte?

bool uartTx(uint8_t data) {
	uint16_t timeout = UART_TIMEOUT/UART_DS;
	while (timeout--) {
		if (uartTxReady()) { UDR = data; return true; }
		else { _delay_us(UART_DS); }
	}
	return false;
}

void uartInit(void) {
	UBRRH = UBRRH_VALUE;
	UBRRL = UBRRL_VALUE;
	#if USE_2X
		UCSRA |= 1 << U2X;
	#endif
	UCSRB |= (1<<RXEN) | (1<<TXEN); // enable RX & TX
}

#define uartDisable()	do { UCSRB &= ~((1<<RXEN)|(1<<TXEN)); } while (0) // disable RX & TX

