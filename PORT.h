
#include "Library.h"

#ifndef PORT_H_
#define PORT_H_

void setPin(volatile uint8_t *port, uint8_t num_ports, uint8_t pos_ports, uint8_t port_val);
void setPortIO(volatile uint8_t *port, uint8_t mask);
unsigned char buttonState(volatile uint8_t *port_X, uint8_t port_pos);

/*
void deletePin(volatile uint8_t *port, uint8_t mask);
void ledOn(volatile uint8_t *port, uint8_t led_pos);
unsigned char selectPorts(uint8_t nr_of_ports, uint8_t active_ports);
*/

#endif /* PORT_H_ */