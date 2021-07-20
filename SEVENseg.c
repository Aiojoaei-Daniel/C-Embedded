
#include "Library.h"

uint16_t dig = 0, cnt = 0, system_startup = 0; 
unsigned char vect[10]={0x03, 0x9F, 0x25, 0x0D, 0x99, 0x49, 0x41, 0x1F, 0x01, 0x09};
uint8_t hours = 5, minutes = 57;
uint8_t OPEN = 0, CLOSE = 0;
uint8_t toggle = 1;
/*
uint8_t alarm_button = 0, alarm = 0, minus_h_button = 0, plus_h_button = 0, minus_m_button = 0, plus_m_button = 0, ok_button = 0;
uint8_t alarm_h = 23, alarm_m = 3, alarma_setata = 0;
char hour[2];
char min[2];*/

void shiftOut1(unsigned char data)
{
	setPin(&PORTB, 1, ST_CP, LOW);  
	for(int i=0;i<8;i++)
	{  
		setPin(&PORTB, 1, SH_CP, LOW);
		
		if((data&0x80)!=0)			// 0X9F = 1001 1111 
			setPin(&PORTB, 1, DS, HIGH);
	
		else
			setPin(&PORTB, 1, DS, LOW);
		
		setPin(&PORTB, 1, SH_CP, HIGH);
		data<<=1;
		_delay_us(1);
	}
	setPin(&PORTB, 1, ST_CP, HIGH);
}

void initTIMER()
{
	sei();
	TCNT0 = 5; //porneste de la 5 la 255
	setPin(&TIMSK, 1, TOIE0, HIGH); // bit de intrerupere timer0
	setPin(&TCCR0, 1, CS02, HIGH); // prescalar 256 pt ca activam CS02 din registrul TCCR0
	setPortIO(&DDRB, 0xFF);
	setPin(&PORTB, 1, DIGIT1, OFF);
	setPin(&PORTB, 1, DIGIT2, OFF);
	setPin(&PORTB, 1, DIGIT3, OFF);
	setPin(&PORTB, 1, DIGIT4, OFF);
}

ISR (TIMER0_OVF_vect)
{	
	
	/*if(buttonState(&PIND, PD2) == 1 && OPEN == 1 && alarm_button == 0)
	{
		alarm_button = 1;
	}
	
	else if(buttonState(&PIND, PD2) == 0 && alarm_button == 1 && alarm == 0)
	{
		placeCursor(2, 4);
		displayLCD("ALARMA: ");
		alarm = 1;
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
		clearLCD();
		centerLCD("ALARMA!", 1);
		_delay_us(5000);
		clearLCD();
	}*/

	TCNT0 = 5;
	writeTemperature(OPEN);
	
	switch(dig++)
	{
		case 0 :	PORTB |= ( 1 << DIGIT2 ) |  ( 1 << DIGIT3 ) | ( 1 << DIGIT4 );
					shiftOut1(vect[hours/10]);
					setPin(&PORTB, 1, DIGIT1, ON);
		break;
		
		case 1 :	PORTB |= ( 1 << DIGIT1 ) |  ( 1 << DIGIT3 ) | ( 1 << DIGIT4 );
					shiftOut1(vect[hours%10] ^ 0x01);	
					setPin(&PORTB, 1, DIGIT2, ON);
		break;
		
		case 2 :	PORTB |= ( 1 << DIGIT1 ) |  ( 1 << DIGIT2 ) | ( 1 << DIGIT4 );
					shiftOut1(vect[minutes/10]);
					setPin(&PORTB, 1, DIGIT3, ON);
		break;
		
		case 3 :	PORTB |= ( 1 << DIGIT1 ) |  ( 1 << DIGIT2 ) | ( 1 << DIGIT3 );
					shiftOut1(vect[minutes%10]);
					setPin(&PORTB, 1, DIGIT4, ON);
					dig = 0;
		break;
		default : break;
	}
	cnt++;
	
	if(cnt >= 40) //103
	{
		++minutes;
		cnt = 0;
		
		if(minutes>59)
		{
			++hours;
			minutes = 0;
		}
		if(hours > 23)
		{
			hours = 0;
		}
		
		if((hours >= 22 || (hours >= 0 && hours < 6)) && CLOSE == 0)
		{
			CLOSE = 1;
			OPEN = 0;
			systemStatus(OPEN); //CLOSE
		}
		else if((hours >= 6 && hours < 22) && OPEN == 0)
		{
			OPEN = 1;
			CLOSE = 0;
			systemStatus(OPEN); // OPEN
		}
		
		
		
	}
}
