#include "Library.h"

#ifndef ADC_H_
#define ADC_H_

void initADC();
uint16_t readADC(uint8_t pin);
void writeTemperature(uint8_t state);

#endif 