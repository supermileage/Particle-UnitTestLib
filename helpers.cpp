#include "Arduino.h"

extern "C"
char *itoa ( int value, char * str, int base ) {

	if (base == 16) {
		snprintf(str, 33, "%x", value);
	}
	else
	if (base == 8) {
		snprintf(str, 33, "%o", value);
	}
	else {
		snprintf(str, 33, "%d", value);
	}

	return str;
}

extern "C"
char *utoa ( unsigned int value, char * str, int base ) {

	if (base == 16) {
		snprintf(str, 33, "%x", value);
	}
	else
	if (base == 8) {
		snprintf(str, 33, "%o", value);
	}
	else {
		snprintf(str, 33, "%u", value);
	}

	return str;
}

extern "C"
char *ltoa (unsigned long value, char * str, int base ) {

	if (base == 16) {
		snprintf(str, 33, "%lx", value);
	}
	else
	if (base == 8) {
		snprintf(str, 33, "%lo", value);
	}
	else {
		snprintf(str, 33, "%ld", value);
	}

	return str;
}

extern "C"
char *ultoa (unsigned long value, char * str, int base ) {

	if (base == 16) {
		snprintf(str, 33, "%lx", value);
	}
	else
	if (base == 8) {
		snprintf(str, 33, "%lo", value);
	}
	else {
		snprintf(str, 33, "%lu", value);
	}

	return str;
}

extern "C"
uint32_t HAL_RNG_GetRandomNumber(void) {
	// This isn't right, there should be a cryptographically sound random number here,
	// but for testing this will be fine.
	return (uint32_t) rand();
}

/*
Logger::Logger(const char *name) :name(name) {
}

void Logger::trace(const char *fmt, ...) {

}
void Logger::info(const char *fmt, ...) {

}
void Logger::warn(const char *fmt, ...) {

}
void Logger::error(const char *fmt, ...) {

}
*/

const Logger Log("app");

uint32_t g_millis = 0;
uint32_t g_micros = 0;

void setMillis(uint32_t value) {
	g_millis = value;
}

uint32_t millis() {
	return g_millis;
}

void setMicros(uint32_t value) {
	g_micros = value;
}

uint32_t micros() {
	return g_micros;
}

// real millis
// uint32_t millis() {
//     struct timespec ts;

//     clock_gettime(CLOCK_MONOTONIC, &ts);

//     return (uint32_t) (uint64_t)(ts.tv_nsec / 1000000) + ((uint64_t)ts.tv_sec * 1000ull);
// }
