#include <RiseSet.h>

RiseSet::RiseSet(float lat, float lon, float zenith, int8_t tz) {
	_lat = lat;
	_lon = lon;
	_zenith = zenith;
	_tz = tz;
}

void RiseSet::setParametrs(float lat, float lon, float zenith, int8_t tz) {
	_lat = lat;
	_lon = lon;
	_zenith = zenith;
	_tz = tz;
}

float RiseSet::sunrise(uint8_t day, uint8_t month, uint16_t year) {
	float rad = 180/pi;
	int nd1 = floor(275.0*(float)month/9.0);
	int nd2 = floor(((float)month + 9.0)/12.0);
	int nd3 = (1 + floor(((float)year - 4.0 * floor((float)year/4.0) + 2.0)/3.0));
	int n_day = nd1 - (nd2 * nd3) + (int)day - 30;
	float lonH = _lon / 15.0;
	float t = n_day + (6.0 - lonH)/24.0;
	float M = 0.9856 * t - 3.289;
	float L = M + 1.916*sin(M/rad) + 0.02*sin(2*M/rad) + 282.634;
	if (L > 360) { L = L-360; }
	if (L < 0) { L = L + 360; }
	float tanRA = 0.91746*tan(L/rad);
	float RA = atan(tanRA)*rad;
	if (RA > 360) { RA = RA-360; }
	if (RA < 0) { RA = RA + 360; }
	float L_q = (floor(L/90.0))*90.0;
	float RA_q = (floor(RA/90.0))*90.0;
	RA = (RA + (L_q - RA_q))/15.0;
	float sinLat = sin(_lat/rad);
	float cosLat = cos(_lat/rad);
	float sinD = 0.39782 * sin(L/rad);
	float cosD = cos(asin(sinD));
	float cosZ = cos(_zenith/rad);
	float cosH = (cosZ - sinD * sinLat)/(cosD*cosLat);
	float H = (360 - acos(cosH)*rad)/15.0;
	float T = H + RA - 0.06571*t - 6.622;
	float UT = T - lonH + _tz;
	if (UT > 24) { UT = UT - 24; }
	if (UT < 0) { UT = UT + 24; }
	return UT;
}

float RiseSet::sunset(uint8_t day, uint8_t month, uint16_t year) {
	float rad = 180/pi;
	int nd1 = floor(275.0*(float)month/9.0);
	int nd2 = floor(((float)month + 9.0)/12.0);
	int nd3 = (1 + floor(((float)year - 4.0 * floor((float)year/4.0) + 2.0)/3.0));
	int n_day = nd1 - (nd2 * nd3) + (int)day - 30;
	float lonH = _lon / 15.0;
	float t = n_day + (18.0 - lonH)/24.0;
	float M = 0.9856 * t - 3.289;
	float L = M + 1.916*sin(M/rad) + 0.02*sin(2*M/rad) + 282.634;
	if (L > 360) { L = L-360; }
	if (L < 0) { L = L + 360; }
	float tanRA = 0.91746*tan(L/rad);
	float RA = atan(tanRA)*rad;
	if (RA > 360) { RA = RA-360; }
	if (RA < 0) { RA = RA + 360; }
	float L_q = (floor(L/90.0))*90.0;
	float RA_q = (floor(RA/90.0))*90.0;
	RA = (RA + (L_q - RA_q))/15.0;
	float sinLat = sin(_lat/rad);
	float cosLat = cos(_lat/rad);
	float sinD = 0.39782 * sin(L/rad);
	float cosD = cos(asin(sinD));
	float cosZ = cos(_zenith/rad);
	float cosH = (cosZ - sinD * sinLat)/(cosD*cosLat);
	float H = (acos(cosH)*rad)/15.0;
	float T = H + RA - 0.06571*t - 6.622;
	float UT = T - lonH + _tz;
	if (UT > 24) { UT = UT - 24; }
	if (UT < 0) { UT = UT + 24; }
	return UT;
}
