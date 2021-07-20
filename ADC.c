#include "Library.h"
uint16_t valADC = 0, tens = 0;

void initADC()
{	
	setPin(&DDRA, 1, PA0, LOW);   
	setPin(&PORTA, 1, PA0, HIGH);
	ADMUX |=  (1 << REFS0) | (1 << MUX0);
	ADCSRA |= (1 <<ADEN) | (1 << ADSC) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); 
}

uint16_t readADC(uint8_t pin)
{
	ADMUX &= 0xF0;
	ADMUX |= 1 << pin;	
	ADCSRA |= (1 << ADSC);
	while(ADCSRA & (1 <<ADSC));
		return ADC;
}

void writeTemperature(uint8_t state)
{
	if(state == 1)
	{
		valADC = readADC(PA0);
		tens = ((uint32_t)(valADC*5)*100)/1024;
	
		uint8_t val[3];
	
		//clearLCD();
		centerLCD("Temp:", LINE1);

		
		//buzzer
		if(tens > 270)
		{
			setPin(&PORTD, 1, 0, HIGH);
		}
		else
		{
			setPin(&PORTD, 1, 0, LOW);
		}
		
		// temp > 30
		if(tens >= 300 && tens <= 390)
		{
			tens = 300;
		}
		if(tens > 390 && tens <= 480)
		{
			tens = 310;
		}
		if(tens > 480)
		{
			tens = 320;
		}
		for(int element=2;element>=0;element--)
		{
			val[element] = tens%10;
			tens /= 10;
			
		}
		
		setPin(&PORTB, 1, PD4, 1);
		setPin(&PORTB, 1, PD5, 0);
		
		placeCursor(LINE1, COL11);
		if(val[0] == 0)
		{
			writeLCD(' ');
			writeLCD(val[1]+'0');
			writeLCD((char)223);
			writeLCD('C');
		}
		else
		{
			writeLCD(val[0]+'0');
			writeLCD(val[1]+'0');
			writeLCD((char)223);
			writeLCD('C');
		}
	}
	else
	{
		setPin(&PORTD, 1, 0, LOW);	
	}
}

