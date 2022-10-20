#include <RiseSet.h>
float lat = 45.0448;
float lon = 38.976;

float zenith = 90.83;	// offical: 90 degrees 50 ' = 90.83
			// civil: 96 degrees
			// nautical: 102 degrees
			// astronomical: 108 degrees
int tz = 3;

uint16_t rise, set;

RiseSet sun;

void setup() {
    Serial.begin(115200);
}

void loop() {
	sun.getRiseSet(31, 1, 2021, &rise, &set);
    Serial.print("Sunrise time: "); Serial.print((int)(rise/60)); Serial.print(':'); Serial.print(rise%60);
    Serial.print("  Sunset time: "); Serial.print((int)(set/60)); Serial.print(':'); Serial.println(set%60);
    delay(3000);
}
