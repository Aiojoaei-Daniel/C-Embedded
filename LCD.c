
#include "Library.h"

void initLCD()
{
	setPortIO(&LCD_comm_dir, 0xFF);
	setPin(&LCD_data_dir, 1, RS, HIGH);
	setPin(&LCD_data_dir, 1, E, HIGH);
	commandLCD(0x38);
	commandLCD(0x01);
	commandLCD(0x06);
	commandLCD(0x0E);
}

void rsON()
{
	setPin(&LCD_data_port, 1, RS, HIGH);
}

void rsOFF()
{
	setPin(&LCD_data_port, 1, RS, LOW);
}

void eON()
{
	setPin(&LCD_data_port, 1, E, HIGH);
}

void eOFF()
{
	setPin(&LCD_data_port, 1, E, LOW);
}

void commandLCD(uint8_t command)
{
	rsOFF();
	eON();
	setPortIO(&LCD_comm_port, command);
	_delay_ms(5);
	eOFF();
}

void writeLCD(uint8_t character)
{
	rsON();  
	eON();
	setPortIO(&LCD_comm_port, character);
	_delay_ms(1);
	eOFF();
}

void placeCursor(uint8_t line, uint8_t col)
{
	if(line == 1)
	{
		commandLCD(col + 128);
	}
	else if(line == 2)
	{
		commandLCD(col + 192);
	}
}

void clearLCD()
{
	commandLCD(0x01);
}

void clearLCD2()
{
	commandLCD(0x02);	// 
}

void displayLCD(char *string)
{		
	while(*string)
	{
		writeLCD(*string++);
	}
}

void centerLCD(char *str, uint8_t line)
{
	uint8_t cnt1 = 0, center_pos = 0;	
	char *cnt2 = str;
	
	while(*cnt2)
	{
		cnt2++;
		cnt1++;
	}
	center_pos = ((16 - cnt1) / 2) + 1 ;
	placeCursor(line, center_pos);
	displayLCD(str);
}

void circularShift(char *str, uint8_t row)
{
	uint8_t cnt1 = 0, pos = 0;
	int8_t col = 0;
	char *cnt2 = str;
	while(1)
	{
		while(*cnt2)
		{
			cnt2++;
			cnt1++;
		}
	
		pos = (16 - cnt1) + 1;
		cnt2 = str;
	
		for(col = pos + cnt1; col > -cnt1; col--)
		{
			placeCursor(row, col);
			displayLCD(cnt2);
			_delay_ms(200);
			clearLCD();
			cnt2 = str;
		}
		cnt1 = 0;
		placeCursor(row, LINE1);
		cnt2 = str;
		displayLCD(cnt2);
	}
}