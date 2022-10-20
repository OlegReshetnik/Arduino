#include <TinyTM1637.h>

#define PIN_DAT		1
#define PIN_CLK		2

uint16_t tt = 0;

TinyTM1637 <PIN_DAT, PIN_CLK> tm;


void setup() {
	tm.setBright(7);
	uint8_t i;
	
	for (i=0; i<4; i++) {
		tm.writeByte(i, _8);
		delay(500);
		tm.writeByte(i, _space);
	}

	i=9;
	do {
		tm.writeDigit(3, i--);
		delay(200);
	} while (i);

	tm.writeBytes(_P, _U, _S, _h);
	delay(1000);
}

void loop() {
	tm.writeTime(tt++);
	delay(500);
	tm.colon(false);
	delay(500);
}
