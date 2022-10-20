#include <Ds18b20.h>

#define DS_UPDATE_INTERVAL	900 // 0.9 second
Ds18b20<D1> ds;

void setup() {
	Serial.begin(115200);
}

void loop() {
	Serial.println(ds.getTemp());
	delay(2000);
}
