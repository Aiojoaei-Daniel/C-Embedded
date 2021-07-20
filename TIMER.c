
#include "Library.h"


volatile uint8_t  count = 0;
uint8_t hours = 23, minutes = 59, seconds = 55;

ISR(TIMER0_OVF_vect)
{
	TCNT0 = 5;
	count++;
	if(count >= 250)
	{	
		time();
		count = 0;
	}
	
}
void initTIMER1()
{	
	TCNT0 = 5; 
	setPin(&TIMSK, 1, TOIE0, HIGH); 	
	setPin(&TCCR0, 1, CS02, HIGH); 
}

void time()
{
	if(++seconds >= 60)
	{
		seconds = 0;
		if (++minutes >= 60)
		{
			minutes = 0;
			if(++hours >= 24)
			{
				hours = 0;
			}
		}
	}
}

void timeDisplay()
{
	//initLCD();
	char da[20];
	sprintf(da, "%02d:%02d:%02d", hours, minutes, seconds);
	centerLCD(da, 1);
	
	if(seconds <= 5)
	{
		setPin(&PORTD, 1, 0, HIGH);
		setPin(&PORTD, 2, 0, LOW);
		centerLCD("ALARM!", 2);
	}
	else
	{
		clearLCD();
		setPin(&PORTD, 1, 0, LOW);
		setPin(&PORTD, 2, 0, HIGH);
	}
	
}
