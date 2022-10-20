#ifndef DS18B20_H
#define DS18B20_H

#include <Arduino.h>

#define DS18b20_FLOAT

#ifndef DS_UPDATE_INTERVAL
	#define DS_UPDATE_INTERVAL	1000 // 1 second
#endif

template <uint8_t DS_PIN>
class Ds18b20 {
	public:
		Ds18b20() {
			pinMode(DS_PIN, INPUT);
			digitalWrite(DS_PIN, LOW);
			dsSet12bit();
			dsStart();
			_oldRead = millis();
		}

#if defined(DS18b20_FLOAT)
		float getTemp() {
#else
		int getTemp() {
#endif
			if ((millis() - _oldRead) > DS_UPDATE_INTERVAL) {
				dsRead();
				dsStart();
				_oldRead = millis();
			}
#if defined(DS18b20_FLOAT)
			return (float)( (((uint16_t)data1)<<8) | (uint16_t)data0 ) / 16.0;
#else
			return (int)(  ( (((uint16_t)data1)<<8) | (uint16_t)data0 ) >> 4  );
#endif
		}

	protected:
		bool oneWire_reset() { 
			pinMode(DS_PIN, OUTPUT);
			delayMicroseconds(600);
			pinMode(DS_PIN, INPUT);
			delayMicroseconds(60);
			bool pulse = digitalRead(DS_PIN);
			delayMicroseconds(600);
			return !pulse;
		}

		void oneWire_write(uint8_t data) {
			for (uint8_t i = 8; i; i--) {
				pinMode(DS_PIN, OUTPUT);
				if (data & 1) {
					delayMicroseconds(5);
					pinMode(DS_PIN, INPUT);
					delayMicroseconds(60);
				} else {
					delayMicroseconds(60);
					pinMode(DS_PIN, INPUT);
					delayMicroseconds(5);
				}
				data >>= 1;
			}
		}

		uint8_t oneWire_read() {
			uint8_t data = 0;
			for (uint8_t i = 8; i; i--) {
				data >>= 1;
				pinMode(DS_PIN, OUTPUT);
				delayMicroseconds(2);
				pinMode(DS_PIN, INPUT);
				delayMicroseconds(8);
				if (digitalRead(DS_PIN)) { data |= (1 << 7); }
				delayMicroseconds(60);
			}
			return data;
		}
		
		void dsStart() {
			if (!oneWire_reset()) { return; }
			oneWire_write(0xCC); // Пропуск ROM, т.к. у нас один датчик
			oneWire_write(0x44); // Команда измерить температуру,
		}
		
		void dsRead() {
			if (!oneWire_reset()) {
				data0 = data1 = 0;
				return;
			}
			oneWire_write(0xCC); // Пропуск ROM, т.к. у нас один датчик 
			oneWire_write(0xBE); // Чтение регистров
			data0 = oneWire_read(); // Младший байт температуры * 16
			data1 = oneWire_read(); // Старший байт температуры * 16
		}

		void dsSet12bit() {
			if (!oneWire_reset()) return;         // Проверка присутствия
			oneWire_write(0xCC); // Пропуск ROM, т.к. у нас один датчик 
			oneWire_write(0x4E); // Запись RAM
			oneWire_write(0xFF); // Максимум в верхний регистр тревоги
			oneWire_write(0x00); // Минимум в верхний регистр тревоги
			oneWire_write((3 << 5) | 0x1F); // Запись конфигурации разрешения 12 бит
		}

	private:
		uint32_t _oldRead;
		uint8_t data0, data1;
};

#endif
