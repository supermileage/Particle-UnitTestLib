#ifndef _WIRING_DIGITAL_H_
#define _WIRING_DIGITAL_H_

#include "Common.h"

void pinMode(pin_size_t pin, PinMode pinMode);

void setDigitalRead(PinStatus status);

PinStatus digitalRead(pin_size_t pin);

#endif