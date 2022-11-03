#ifndef _SUPERMILEAGE_FAKE_SERIAL_H_
#define _SUPERMILEAGE_FAKE_SERIAL_H_

#include <functional>
#include <iostream>
#include <stdarg.h>

#include "spark_wiring_string.h"

// fake serial class for tests
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

#define SERIAL_8N1 0	// definition for USART serial flag used in project

// mock class for Particle's USARTSerial
class USARTSerial {
	public:
		~USARTSerial();
		static USARTSerial& instance();
		void begin(unsigned long baud, uint32_t flags);
		int available();
		int read();
		size_t readBytes(char* buffer, size_t length);
		void setReadMessage(std::string message);
		void setBegin(std::function<void(unsigned long, uint32_t)> func);
		void setAvailable(std::function<int(void)> func);
		void setRead(std::function<int(void)> func);
		void setReadBytes(std::function<size_t(char*,size_t)> func);

	private:
		static USARTSerial* _instance;
		std::function<void(unsigned long, uint32_t)> _begin;
		std::function<int(void)> _available;
		std::function<int(void)> _read;
		std::function<size_t(char*,size_t)> _readBytes;

};

#endif