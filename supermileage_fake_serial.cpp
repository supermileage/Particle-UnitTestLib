#include "supermileage_fake_serial.h"

FakeSerial* FakeSerial::_instance = nullptr;

FakeSerial::~FakeSerial() {
	delete _instance;
}

FakeSerial& FakeSerial::instance() {
	if (!_instance)
		_instance = new FakeSerial();
	return *_instance;
}

void FakeSerial::print(String msg) {
	std::cout << msg.c_str();
}

void FakeSerial::println(String msg) {
	std::cout << msg.c_str() << std::endl;
}

void FakeSerial::printf(const char* format, ...) {
	va_list argptr;
	va_start(argptr, format);
	vprintf(format, argptr);
	va_end(argptr);
}