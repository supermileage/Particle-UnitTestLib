#ifndef _COMMON_H_
#define _COMMON_H_

typedef int PinStatus;

typedef enum {
  INPUT           = 0x0,
  OUTPUT          = 0x1,
  INPUT_PULLUP    = 0x2,
  INPUT_PULLDOWN  = 0x3,
} PinMode;

typedef enum {
  LSBFIRST = 0,
  MSBFIRST = 1,
} BitOrder;

typedef int pin_size_t;

#endif