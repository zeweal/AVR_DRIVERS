/*
///////////////////////////////////////////////////////////////////////BUZ_INTERFACE.h\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
Auothor: Abdallah Zeweal
Layer: HAL
SWC: BUZ
*/
#ifndef BUZ_INTERFACE_H_
#define BUZ_INTERFACE_H_


// Port Defines
#define  BUZ_PORTA  0
#define  BUZ_PORTB  1
#define  BUZ_PORTC  2
#define  BUZ_PORTD  3


// PIN Defines
#define BUZ_PIN0   0
#define BUZ_PIN1   1
#define BUZ_PIN2   2
#define BUZ_PIN3   3
#define BUZ_PIN4   4
#define BUZ_PIN5   5
#define BUZ_PIN6   6
#define BUZ_PIN7   7

#define ACTIVE_HIGH    1
#define ACTIVE_LOW     0


typedef struct {
	u8 PIN;
	u8 PORT;
	u8 ACTIVATE_STATE;
}BUZ_TYPE;

void BUZ_INIT(BUZ_TYPE BUZ_CONFIG);
void BUZ_ON(BUZ_TYPE BUZ_CONFIG);
void BUZ_OFF(BUZ_TYPE BUZ_CONFIG);
void BUZ_TOGGLE(BUZ_TYPE BUZ_CONFIG);

#endif
