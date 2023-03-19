#include "supermileage_fake_serial.h"

/* Serial */
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

void FakeSerial::println() {
    std::cout << std::endl;
}

void FakeSerial::printf(const char* format, ...) {
	va_list argptr;
	va_start(argptr, format);
	vprintf(format, argptr);
	va_end(argptr);
}

/* USARTSerial */
USARTSerial* USARTSerial::_instance = nullptr;

USARTSerial::~USARTSerial() { }

USARTSerial& USARTSerial::instance() {
	if (!_instance) {
		_instance = new USARTSerial();
	}

	return *_instance;
}

void USARTSerial::begin(unsigned long baud, uint32_t flags) {
	_begin(baud, flags);
}

int USARTSerial::available() {
	return _available();
}

int USARTSerial::read() {
	return _read();
}

size_t USARTSerial::readBytes(char* buffer, size_t length) {
	return _readBytes(buffer, length);
}

void USARTSerial::setReadMessage(std::string message) {
	int length = message.length();
	_available = [length]() -> int { return length; };
	_readBytes = [message](char* buffer, size_t length) -> size_t {
		strcpy(buffer, message.c_str());
		return strlen(buffer);
	};
}

void USARTSerial::setBegin(std::function<void(unsigned long, uint32_t)> func) {
	_begin = func;
}

void USARTSerial::setAvailable(std::function<int(void)> func) {
	_available = func;
}

void USARTSerial::setRead(std::function<int(void)> func) {
	_read = func;
}

void USARTSerial::setReadBytes(std::function<size_t(char*,size_t)> func) {
	_readBytes = func;
}
