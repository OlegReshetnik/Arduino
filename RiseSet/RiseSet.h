#pragma once

#include <Arduino.h>

const float pi = 3.14159265358979323846;

class RiseSet
{
	public:
		RiseSet(float lat = 45.0448, float lon = 38.976, float zenith = 90.83, int8_t tz = 3); // default Krasnodar
		void setParametrs(float lat, float lon, float zenith = 90.83, int8_t tz = 3);

		float sunrise(uint8_t month, uint8_t day, uint16_t year);
		float sunset(uint8_t month, uint8_t day, uint16_t year);

		void getRiseSet(uint8_t day, uint8_t month, uint16_t year, uint16_t * rise_time, uint16_t * set_time) {
			*rise_time = sunrise(day, month, year) * 60.0;
			*set_time = sunset(day, month, year) * 60.0;
		}

	private:
		float _lat;
		float _lon;
		float _zenith;
		int8_t _tz;
};
