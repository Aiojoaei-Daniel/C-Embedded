
#include "Library.h"

#ifndef LCD_H_
#define LCD_H_

void initLCD();
void commandLCD(uint8_t command);
void writeLCD(uint8_t character);
void placeCursor(uint8_t line, uint8_t col);
void clearLCD();
void clearLCD2();
void rsON();
void rsOFF();
void eON();
void eOFF();
void displayLCD(char *string);
void centerLCD(char *str, uint8_t line);
void circularShift(char *str, uint8_t row);

#endif /* LCD_H_ */