
#include "Library.h"

void setPin(volatile uint8_t *port, uint8_t num_ports, uint8_t pos_ports, uint8_t port_val)
{	
	if(port_val == 1)
	{
		*port |= (num_ports << pos_ports);
	}
	else
	{
		*port &= ~(num_ports << pos_ports);
	}
}

void setPortIO(volatile uint8_t *port, uint8_t mask)
{
		*port = mask;
}

unsigned char buttonState(volatile uint8_t *port_X, uint8_t port_pos)
{
	if((*port_X & (1 << port_pos)) == (1 << port_pos))
	{
		return 0; // nu e apasat
	}
	else
		return 1; // e apasat
}

/*
void deletePin(volatile uint8_t *port, uint8_t bit)
{
	*port &= ~(1 << bit);
}*/

/*
void ledOn(volatile uint8_t *port, uint8_t led_pos)
{
	*port = ~(1 << led_pos);
}*/

