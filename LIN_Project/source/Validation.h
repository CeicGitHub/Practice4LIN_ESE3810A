#ifndef VALIDATION
#define VALIDATION

#include <stdint.h>

uint8_t calculate_parity(uint8_t header);
uint8_t validate_parity(uint8_t header);

#endif