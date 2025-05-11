#ifndef CAN_PRIVATE_H_
#define CAN_PRIVATE_H_

#define CNF1     0x2A
#define CNF2     0x29
#define CNF3     0x28

/*
#define CANCTRL  0x0F
#define CANSTAT  0x0E
*/

#define CAN_MODE_CONFIG 0x4
#define CAN_MODE_NORMAL 0x0

#define TXB0CTRL   *((volatile u8*)0b00110000)
#define TXB0SIDH   *((volatile u8*)0b00110001)
#define TXB0SIDL   *((volatile u8*)0b00110010)
#define TXB0EID8   *((volatile u8*)0b00110011)
#define TXB0EID0   *((volatile u8*)0b00110100)
#define TXB0DLC    *((volatile u8*)0b00110101)
#define TXB0D0     *((volatile u8*)0b00110110)
#define TXB0D1	   *((volatile u8*)0b00110111)
#define TXB0D2     *((volatile u8*)0b00111000)
#define TXB0D3     *((volatile u8*)0b00111001)
#define TXB0D4     *((volatile u8*)0b00111010)
#define TXB0D5     *((volatile u8*)0b00111011)
#define TXB0D6     *((volatile u8*)0b00111100)
#define TXB0D7     *((volatile u8*)0b00111101)
#define CANSTAT    *((volatile u8*)0b00111110)
#define CANCTRL    *((volatile u8*)0b00111111)

#endif