// small soft uart library
#pragma once
#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>

#include <avr_io.h>

#if !defined(S_UART_SPEED)
	#define S_UART_SPEED	4800UL
#endif

#if !defined(S_UART_TIMEOUT)
	#define S_UART_TIMEOUT	(1000000UL) // 1 seconds
#endif

#define S_UART_D			(1000000UL/S_UART_SPEED) // bit delay
#define S_UART_DS			(1000000UL/(S_UART_SPEED*4UL)) // 1/4 bit delay

//------------- transmit --------------------------
#ifdef S_UART_TRANSMIT

#if !defined(S_UART_OUT)
	#define S_UART_OUT			IOB4
#endif

void sUartTxInit(void) { // pins setup
	SET_OUTPUT(S_UART_OUT);
	SET1(S_UART_OUT);
}

void sUartTxBit(uint8_t bit) {
	WRITE(S_UART_OUT, bit);
	_delay_us(S_UART_D); // bit_delay
}

void sUartTx(uint8_t txb) { // transmit byte
	uint8_t cnt = 8;

	sUartTxBit(0); // start bit
	while (cnt--) {
		sUartTxBit(txb&1); // Least Significant Bit
		txb >>= 1;
	}
	sUartTxBit(1); // stop bit
	sUartTxBit(1); // stop bit
}

#endif // S_UART_TRANSMIT
//------------- end transmit ----------------------

//------------- recive --------------------------
#ifdef S_UART_RECIVE

#if !defined(S_UART_IN)
	#define S_UART_IN		IOB3
#endif

#define sUartRxReady()		(READ(S_UART_IN) == 0)

void sUartRxInit(void) { // pins setup
	SET_INPUT(S_UART_IN);
	//PULLUP_ON(S_UART_IN);
}

uint8_t sUartRxBit(void) {
	_delay_us(S_UART_D); // bit_delay
	return READ(S_UART_IN);
}

uint8_t sUartRx(void) { // recive byte
	uint8_t cnt = 8, rxb = 0;

	_delay_us(S_UART_DS); // delay to center start bit

	while (cnt--) {
		rxb >>= 1;
		if (sUartRxBit()) { rxb |= 0x80; } // Least Significant Bit
	}
	sUartRxBit(); // skip to stop bit
	return rxb;
}

bool sUartWaitRx(void) { // wait start bit
	uint16_t timeout = S_UART_TIMEOUT/S_UART_DS;
	
	while (timeout--) {
		if (sUartRxReady()) { return true; }
		_delay_us(S_UART_DS);
	}
	return false;
}
#endif // S_UART_RECIVE
//------------- end recive ----------------------
