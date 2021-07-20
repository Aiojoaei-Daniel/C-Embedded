
#include "Library.h"


int main(void)	
{
	/////////////////////////////ADC PORT	
	/*DDRA &=~(1<<PA0);	
	PORTA = 0x01;
	DDRD |= 0x30;*/
	

	setPin(&DDRD, 1, 0, HIGH);
	
	/////////////////////////////SYSTEM PORT
	setPin(&DDRA, 0xC0, 0, 1);
	
	//////////////////////////BUTTONS

	DDRD &= ~0x04;
	setPin(&PORTD, 1, PD2, 1);
	setPin(&PORTB, 1, PD2, 1);
	DDRA &= ~0x3F;
	setPin(&PORTA, 0x3F, 0, 1);

	initLCD();
	/*centerLCD("Welcome to...", LINE1);
	_delay_ms(2000);
	clearLCD();
	centerLCD("Smart Home!", LINE1);
	_delay_ms(3000);
	clearLCD();*/

	initTIMER();
	initADC();
	
	while(1)
	{
		setAlarm();
	}
	
}
	
