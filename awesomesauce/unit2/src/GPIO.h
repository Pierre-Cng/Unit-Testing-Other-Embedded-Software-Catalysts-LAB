#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

void GPIO_SetPinAsOutput(uint8_t Pin);
void GPIO_SetPinAsInput(uint8_t Pin);

#endif //GPIO_H
