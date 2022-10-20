#ifndef _TINYTM1637_H_
#define _TINYTM1637_H_

#ifdef __AVR__
	#include <avr/pgmspace.h>
#elif defined(ESP8266) || defined(ESP32)
	#include <pgmspace.h>
#endif

//      Bits:                 Hex:
//        -- 0 --               -- 01 --
//       |       |             |        |
//       5       1            20        02
//       |       |             |        |
//        -- 6 --               -- 40 --
//       |       |             |        |
//       4       2            10        04
//       |       |             |        |
//        -- 3 --  .7           -- 08 --   .80

#define _A 0x77
#define _B 0x7f
#define _C 0x39
#define _D 0x3f
#define _E 0x79
#define _F 0x71
#define _G 0x3d
#define _H 0x76
#define _J 0x1e
#define _L 0x38
#define _N 0x37
#define _O 0x3f
#define _P 0x73
#define _S 0x6d
#define _U 0x3e
#define _Y 0x6e
#define _a 0x5f
#define _b 0x7c
#define _c 0x58
#define _d 0x5e
#define _e 0x7b
#define _f 0x71
#define _h 0x74
#define _i 0x10
#define _j 0x0e
#define _l 0x06
#define _n 0x54
#define _o 0x5c
#define _q 0x67
#define _r 0x50
#define _t 0x78
#define _u 0x1c
#define _y 0x6e
#define _minus 0x40
#define _under 0x08
#define _equal 0x48
#define _degree 0x63
#define _err 0x49
#define _plus 0x44
#define _space 0x00

#define _0 0x3f
#define _1 0x06
#define _2 0x5b
#define _3 0x4f
#define _4 0x66
#define _5 0x6d
#define _6 0x7d
#define _7 0x07
#define _8 0x7f
#define _9 0x6f

#define _dot 0x80

#define TM1637_DIGITS   4
#define COLON_POS		1

// Instructions
#define TM_DATA_CMD             0x40
#define TM_DISP_CTRL            0x80
#define TM_ADDR_CMD             0xC0

// Data command set
#define TM_WRITE_DISP           0x00
#define TM_READ_KEYS            0x02
#define TM_FIXED_ADDR           0x04

// Display control command
#define TM_DISP_PWM_MASK        0x07 // First 3 bits are brightness (PWM controlled)
#define TM_DISP_ENABLE          0x08

#define DELAY_US                10

const uint8_t digits[] PROGMEM = { _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _A, _B, _C, _D, _E, _F };

template < uint8_t DAT, uint8_t CLK >
class TinyTM1637 {
public:
	TinyTM1637() {
		pinMode(DAT, OUTPUT);
		pinMode(CLK, OUTPUT);
		_send_cmd(TM_DATA_CMD | TM_WRITE_DISP);
		_send_cmd(TM_DISP_CTRL | TM_DISP_ENABLE | TM_DISP_PWM_MASK);
		clear();
	}

	void clear(void) {
		for (uint8_t a = 0; a < TM1637_DIGITS; ++a) { _send_data(a, _space); }
	}

	void setBright(const uint8_t brightness) { _send_cmd(TM_DISP_CTRL | TM_DISP_ENABLE | (brightness & TM_DISP_PWM_MASK)); }

	void writeByte(const uint8_t position, const uint8_t b) {
		_send_data(position, b | _colon_mask );
		if (position == COLON_POS) _byte_colon = b;
	}

	void writeBytes(const uint8_t b0, const uint8_t b1, const uint8_t b2, const uint8_t b3) {
		writeByte(0, b0);
		writeByte(1, b1);
		writeByte(2, b2);
		writeByte(3, b3);
	}

	void writeDigit(const uint8_t position, const uint8_t digit) { writeByte(position, pgm_read_byte(&digits[digit&0xF])); }

	void colon(bool on) {
		if (on) { _colon_mask = _dot; }
		else { _colon_mask = 0; }
		_send_data(COLON_POS, _byte_colon | _colon_mask);
	}

	void writeTime(uint16_t sec) {
		uint8_t mm = sec / 60, ss = sec % 60;
		_colon_mask = _dot;
		writeDigit(0, mm / 10);
		writeDigit(1, mm % 10);
		writeDigit(2, ss / 10);
		writeDigit(3, ss % 10);
	}

	void writeInt(uint16_t val) {
		_colon_mask = 0;
		writeDigit(0, val/1000);
		writeDigit(1, (val/100)%10);
		writeDigit(2, (val/10)%10);
		writeDigit(3, val%10);
	}

private:
	void _start(void) {
		digitalWrite(CLK, 1);
		digitalWrite(DAT, 1);
		//digitalWrite(CLK, 0);
		digitalWrite(DAT, 0);
	}

	void _stop(void) {
		digitalWrite(CLK, 0);
		digitalWrite(CLK, 1);
		digitalWrite(DAT, 0);
		digitalWrite(DAT, 1);
	}

	void _send(uint8_t b) {
		for (uint8_t i = 0; i<8; i++) { // Clock data bits
			digitalWrite(CLK, 0);
			digitalWrite(DAT, b & 0x01);
			b >>= 1;
			digitalWrite(CLK,1);
		}

		digitalWrite(CLK, 0);
		digitalWrite(DAT, 0);
		digitalWrite(CLK, 1);
		//delayMicroseconds(DELAY_US);
	}

	void _send_cmd(const uint8_t cmd) {
		_start();
		_send(cmd);
		_stop();
	}

	void _send_data(const uint8_t addr, const uint8_t data) {
		_send_cmd(TM_DATA_CMD | TM_FIXED_ADDR);
		_start();
		_send(TM_ADDR_CMD | addr);
		_send(data);
		_stop();
	}

	uint8_t _colon_mask = 0, _byte_colon = 0;
};

#endif // _TINYTM1637_H_
