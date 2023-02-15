#include "wiring_digital.h"

void pinMode(pin_size_t pin, PinMode pinMode) { }

PinStatus g_pinStatus = 0;

void setDigitalRead(PinStatus status) {
    g_pinStatus = status;
}

PinStatus digitalRead(pin_size_t pin) {
    return (PinStatus)g_pinStatus;
}
