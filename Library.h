
#ifndef LIBRARY_H_
#define LIBRARY_H_

#define F_CPU 16000000

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
//#include <xc.h>

#include "LCD.h"
#include "ADC.h"
#include "TIMER.h"
#include "SYSTEM.h"
#include "SEVENseg.h"
#include "PORT.h"

//PORTS
#define INPUT 0
#define OUTPUT 1
#define HIGH 1
#define LOW 0 

//DELAY
#define delay_05 500
#define delay_1 1000
#define delay_2 2000
#define delay 5

//BUTTONS

#define BUTTON0 0
#define BUTTON1 1
#define BUTTON2 2
#define BUTTON3 3
#define BUTTON4 4
#define BUTTON5 5
#define BUTTON6 6
#define BUTTON7 7

//LCD

#define LCD_data_dir DDRD
#define LCD_comm_dir DDRC
#define LCD_data_port PORTD
#define LCD_comm_port PORTC
#define RS PD6
#define E PD7


//LINES

#define LINE1 1
#define LINE2 2

//COLUMNS

#define COL0 0 
#define COL1 1
#define COL2 2
#define COL3 3

#define COL4 4
#define COL5 5
#define COL6 6
#define COL7 7

#define COL8 8
#define COL9 9
#define COL10 10
#define COL11 11

#define COL12 12
#define COL13 13
#define COL14 14
#define COL15 15

//ADC

#define ADC_data_dir DDRA
#define ADC_data_port PORTA
#define ADC_port PA1 


//7SEG

#define SH_CP PB5
#define DS PB6
#define ST_CP PB7
#define DIGIT1 PB3
#define DIGIT2 PB4
#define DIGIT3 PB1
#define DIGIT4 PB0
#define ON 0
#define OFF 1
/*
#define CLOSE 0
#define OPEN 1*/



#endif /* LIBRARY_H_ */