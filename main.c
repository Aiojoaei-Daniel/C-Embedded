
#include "Library.h"

/*
uint8_t toggle = 1;

ISR (INT0_vect)
{
	setPin(&PORTB, 1, PB4, toggle);
	toggle ^= 1;
	_delay_ms(50);
}
*/

int main(void)		////////////////////////////// CEL MAI SIMPLU AR FI SA DECLARAM TOATE PORTURILE IN MAIN SAU
{
	/////////////////////////////ADC PORT	
	/*DDRA &=~(1<<PA0);	
	PORTA = 0x01;
	DDRD |= 0x30;*/
	

	setPin(&DDRD, 1, 0, HIGH);
	//setPin(&PORTD, 1, 0, LOW);
	
	/////////////////////////////SYSTEM PORT
	setPin(&DDRA, 0xC0, 0, 1);
	
	////////////////////////////INTERRUPT
	/*setPin(&GICR, 1, INT0, 1);
	MCUCR = 1 << ISC01 | 1 << ISC00;
	setPin(&PORTB, 1, PB4, 0);
	setPin(&DDRD, 1, PD2, 0);
	setPin(&PORTD, 1, PD2, 1);*/
	
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
	
	/*if(alarm == 1)
	{
		placeCursor(2, 4);
		displayLCD("ALARMA: ");
	}*/
	/*placeCursor(2, 4);
	displayLCD("ALARMA: ");*/
	
	while(1)		// SA VAD CUM SA FAC CLEAR LCD DOAR PE ZONE
	{
		setAlarm();
	}
	
}
	/*DDRA &=~(1<<PA0);
	PORTA = 0x01;
	DDRD |= 1;
	DDRD |= 0x30;
	setPin(&PORTD, 1, 0, LOW);
	
	uint16_t valADC = 0, tens = 0;
	uint8_t val[3];
	
	clearLCD();
	while(1)
	{
		centerLCD("Temp:", LINE1);

		valADC = readADC(PA0);
		tens = ((uint32_t)(valADC*5)*100)/1024;
		
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
			//placeCursor(LINE1, COL11);
			writeLCD(val[1]+'0');
			writeLCD((char)223);
			writeLCD('C');
		}
		else
		{
			//placeCursor(LINE1, COL11);
			writeLCD(val[0]+'0');
			writeLCD(val[1]+'0');
			writeLCD((char)223);
			writeLCD('C');
		}
	}*/




/*
	/////////////////////////////7SEG
#include "Library.h"
#define swCount ((PINA&0x01)==0)


int main(void)
{
	unsigned char vec_num[10]={0x03, 0x9F, 0x25, 0x0D, 0x99, 0x49, 0x41, 0x1F, 0x01, 0x09};
	unsigned char cnt=0;
	DDRB=0xFF;
	DDRA=0xFE;
	PORTA=0x01;
	PORTB = 0x0E; // activez ultimul digit
	/ *while (1)
	{
		cnt++;
		if(cnt < 10){
			PORTB = 0x0E;
			_delay_ms(1000);
		}
		else if(cnt>=10){ 
			PORTB = 0x0D; 
			cnt=0;
		}
		shiftOut(ssd[cnt]);
	}* /
	//numara automat
	/ *while (1)
	{
		cnt++;
		_delay_ms(500);
		if(cnt>=10) 
			cnt=0;
		shiftOut1(vec_num[cnt]);
	}* /
	// creste valoarea cand apesi pe buton
		while (1)
	{
		if(swCount) cnt++;
			_delay_ms(300);
		if(cnt>=10)		
			cnt=0;
		shiftOut1(vec_num[cnt]);
	}
}*/

////////////////////////////////////////////// ADC
	
	/*initLCD();
	initADC();
	PORTA = 0xFF;
	DDRA &=~(1<<PA0);
	
	uint16_t valADC = 0, tens = 0;
	uint8_t val[3];
	int element = 0;
	_delay_ms(10);

	placeCursor(1,2);
	displayLCD("TENS: ");
	while(1)
	{
		
		valADC = readADC(0);
		tens = ((uint32_t)(valADC*5)*100)/1024;
		for(element=2;element>=0;element--)
		{
			val[element] = tens%10;
			tens /= 10;
			
		}
		placeCursor(1,7);
		writeLCD(val[0]+'0');
		writeLCD('.');
		writeLCD(val[1]+'0');
		writeLCD(val[2]+'0');
	}*/
	
	/////////////////////////////////////////////LCD     
	///EX1 
	//placeCursor(LINE2, COL10);
	//writeLCD('V');
	
	//////EX2
	//placeCursor(LINE2, COL2);
	//displayString("1234");
	//centerLCD("Vitesco", LINE1);
	//centerLCD("Technologies", LINE2);
	
	/*// EX3
	initLCD();
	while(1)
	{
	circularShift("practica", LINE1);
	}
	}*/
	
/*
	int main(void)
	{
		////////////////////////////////////////////////////////////////////////// TIMMER
		sei(); // activam primirea întreruperilor
		//initLCD();

		initTIMER1();
		setPortIO(&DDRD, 3);
		
		while (1)
		{
			timeDisplay();
		}

	}*/


//////////////////////////////////////////////////////////////////////////7SEG
/*
unsigned char cnt=0;

	//numara automat
	while (1)
	{
		cnt++;
		_delay_ms(500);
		setPin(&PORTB, 0x0E, 0, 1);
		if(cnt>=10)
		cnt=0;
		shiftOut1(vec_num[cnt]);
	}
	// creste valoarea cand apesi pe buton
	/ *while (1)
	{
		if(swCount) cnt++;
		_delay_ms(300);
		if(cnt>=10)
		cnt=0;
		shiftOut1(vec_num[cnt]);
	}*/