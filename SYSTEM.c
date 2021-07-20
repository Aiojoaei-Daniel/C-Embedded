
#include "Library.h"

uint8_t alarm_button = 0, alarm = 0, minus_h_button = 0, plus_h_button = 0, minus_m_button = 0, plus_m_button = 0, ok_button = 0;
uint8_t alarm_h = 23, alarm_m = 3, alarma_setata = 0;
char hour[2];
char min[2];

void systemStatus(uint8_t status)
{	
	if(status == 0)	
	{
		//clearLCD();
		placeCursor(2, 0);
		displayLCD("OFF");
		setPin(&PORTA, 1, PB7, ON);
		setPin(&PORTA, 1, PB6, OFF);
	}
	else if(status == 1)				
	{	
		//clearLCD();
		placeCursor(2, 0);
		displayLCD("ON ");
		setPin(&PORTA, 1, PB6, ON);
		setPin(&PORTA, 1, PB7, OFF);
		
	}
	
}

void setAlarm()
{
	if(buttonState(&PIND, PD2) == 1  && alarm_button == 0)	//&& OPEN == 1
		{
			alarm_button = 1;
		}
		
		 if(buttonState(&PIND, PD2) == 0 && alarm_button == 1 && alarm == 0)
		{
			placeCursor(2, 4);
			displayLCD("ALARMA: ");
			//alarm = 1;
			PORTB &= ~(1<<PB2);
		}
		if(alarm_button == 1)
		{
			//ORE
			if(buttonState(&PINA, PA0) == 1 && minus_h_button == 0)
			{
				minus_h_button = 1;
			}
			else if(buttonState(&PINA, PA0) == 0 && minus_h_button == 1)
			{
				
				minus_h_button = 0;
				if(alarm_h == 0)
				{
					alarm_h = 24;
				}
				alarm_h--;
			}
			if(buttonState(&PINA, PA2) == 1 && plus_h_button == 0)
			{
				plus_h_button = 1;
			}
			else if(buttonState(&PINA, PA2) == 0 && plus_h_button == 1)
			{
				alarm_h++;
				plus_h_button = 0;
				if(alarm_h >= 24)
				{
					alarm_h = 0;
				}
			}
			//MINUTE
			if(buttonState(&PINA, PA3) == 1 && minus_m_button == 0)
			{
				minus_m_button = 1;
			}
			else if(buttonState(&PINA, PA3) == 0 && minus_m_button == 1)
			{
				
				minus_m_button = 0;
				if(alarm_m == 0)
				{
					alarm_m = 60;
					alarm_h--;
				}
				alarm_m--;
			}
			if(buttonState(&PINA, PA4) == 1 && plus_m_button == 0)
			{
				plus_m_button = 1;
			}
			else if(buttonState(&PINA, PA4) == 0 && plus_m_button == 1)
			{
				alarm_m++;
				plus_m_button = 0;
				if(alarm_m > 59)
				{
					alarm_m = 0;
					alarm_h++;
				}
			}
			hour[1] = alarm_h % 10;
			hour[0] = alarm_h / 10;
			
			min[0] = alarm_m / 10;
			min[1] = alarm_m % 10;

			placeCursor(2, 11);
			writeLCD(hour[0] + '0');
			writeLCD(hour[1] + '0');
			writeLCD(':');
			writeLCD(min[0] + '0');
			writeLCD(min[1] + '0');
			
			if(buttonState(&PINA, PA5) == 1 && ok_button == 0)
			{
				ok_button = 1;
			}
			else if(buttonState(&PINA, PA5) == 0 && ok_button == 1)
			{
				alarm_button = 0;
				alarma_setata = 1;
			}
			
		}
		if(alarm_h == hours && alarm_m == minutes && alarma_setata)
		{
			//clearLCD();
			centerLCD("ALARMA!", 1);
			_delay_us(5000);
			//clearLCD();
		}
}