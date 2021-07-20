#include "Library.h"

#ifndef SEVENSEG_H_
#define SEVENSEG_H_

void shiftOut1(unsigned char data);
void initTIMER();
extern uint8_t hours, minutes;
extern uint8_t OPEN, CLOSE;
/*void systemStatus1(uint8_t status);*/

#endif /* SEVENSEG_H_ */