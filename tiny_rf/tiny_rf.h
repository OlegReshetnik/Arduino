// small rf library, send & recive one uint16_t
// use externall micros()
#pragma once
#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>

#include <avr_io.h>

#define TINY_RF_INTERVAL	420 // protocol cntnterval

//------------- transmit --------------------------
#ifdef TINY_RF_TRANSMIT

#if !defined(TINY_RF_OUT)
	#define TINY_RF_OUT		IOB2
#endif

void tinyRfTxInit(void) { // pins setup
	SET_OUTPUT(TINY_RF_OUT);
	SET0(TINY_RF_OUT);
}

void __send1(uint8_t hlen, uint8_t llen) { // send `````|____
	SET1(TINY_RF_OUT); while(hlen--) { _delay_us(TINY_RF_INTERVAL); }
	SET0(TINY_RF_OUT); while(llen--) { _delay_us(TINY_RF_INTERVAL); }
}

void __send16(uint16_t ww) {
	for (uint8_t bcnt=0; bcnt<16; bcnt++) { // MSB
		if (ww&0x8000) { __send1(1,2); } // send "1"
		else { __send1(2,1); } // send "0"
		ww <<= 1;
	}
}

void tinyRfTx(uint16_t txw) { // send word
	for (uint8_t rep = 0; rep < 4; rep++) { // repeat 4
		for (uint8_t i = 0; i < 20; i++) { __send1(1,1); } // send 20 synchro pulse
		__send1(1,5); // send start
		__send16(txw);
		__send16(~txw);
		__send1(5,42); // end & pause
	}
}
#endif // TINY_RF_TRANSMIT
//------------- end transmit ----------------------

//------------- recive --------------------------
#ifdef TINY_RF_RECIVE

extern uint32_t micros(void);

#if !defined(TINY_RF_IN)
	#define TINY_RF_IN		IOB1
#endif

void tinyRfRxInit(void) { SET_INPUT(TINY_RF_IN); }// pins setup

#define CHEK_CALIBR(LEN, CALIBR)	( ((LEN) > ((CALIBR*2)/3)) && ((LEN) < ((CALIBR*4)/3)) )

uint8_t __trf_bitcnt = 0;
uint16_t __trf_data = 0;
uint16_t __trf_Ndata = 0;

void __sero(void) {
	__trf_bitcnt = 0;
	__trf_data = 0;
	__trf_Ndata = 0;
}

#define tinyRfRxReady()	(__trf_bitcnt == 32) 

uint16_t tinyRfRx(void) {
	__trf_bitcnt = 0;
	return __trf_data;
}

void tinyRfRxTick(void) { // tick
	static uint32_t lastTime = 0;
	static uint8_t oldIn = 0;

	if (tinyRfRxReady()) { return; }

	const uint8_t In = READ(TINY_RF_IN);

	if (oldIn == In) { return; }

	if (In) { // _____|`````` get to "1"
		const uint16_t Delta = (uint16_t)(micros() - lastTime);
		//if (CHEK_CALIBR(Delta, TINY_RF_INTERVAL*5)) { __sero(); }// get "start"
		if (CHEK_CALIBR(Delta, TINY_RF_INTERVAL*2)) { // get "1"
			if (__trf_bitcnt < 16) { __trf_data <<= 1; __trf_data |= 1; }// MSB
			else { __trf_Ndata <<= 1; __trf_Ndata |= 1; }
			if ((++__trf_bitcnt==32) && (__trf_data != (~__trf_Ndata))) { __sero(); }
		}
		else if (CHEK_CALIBR(Delta, TINY_RF_INTERVAL)) { // get "0"
			if (__trf_bitcnt < 16) { __trf_data <<= 1; }// MSB
			else { __trf_Ndata <<= 1; }
			if ((++__trf_bitcnt==32) && (__trf_data != (~__trf_Ndata))) { __sero(); }
		}
		else { __sero(); }
	}
	else { lastTime = micros(); } //`````|____ get to "0"

	oldIn = In;
}
#endif // TINY_RF_RECIVE
//------------- end recive ----------------------
