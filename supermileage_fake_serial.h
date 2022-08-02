#ifndef _SUPERMILEAGE_FAKE_SERIAL_H_
#define _SUPERMILEAGE_FAKE_SERIAL_H_

#include <iostream>
#include <stdarg.h>

#include "spark_wiring_string.h"

class FakeSerial {
	public:
		~FakeSerial();
		static FakeSerial& instance();
		void print(String msg);
		void println(String msg);
		void printf(const char* format, ...);
	private:
		static FakeSerial* _instance;
		FakeSerial() { }
};

#endif