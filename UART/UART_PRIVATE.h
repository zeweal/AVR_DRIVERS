#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_


#define UDR     *((volatile u8*)0x2C)

#define UCSRA    *((volatile u8*)0x2B)
//its bits
#define UCSRA_MPCM 0
#define UCSRA_U2X  1
#define UCSRA_PE   2
#define UCSRA_DOR  3
#define UCSRA_FE   4
#define UCSRA_UDRE 5
#define UCSRA_TXC  6
#define UCSRA_RXC  7

#define UCSRB    *((volatile u8*)0x2A)
//its bits
#define UCSRB_TXB8  0
#define UCSRB_RXB8  1
#define UCSRB_UCSZ2 2
#define UCSRB_TXEN  3
#define UCSRB_RXEN  4
#define UCSRB_UDRIE 5
#define UCSRB_TXCIE 6
#define UCSRB_RXCIE 7

#define UCSRC    *((volatile u8*)0x40)
//its bits 
#define UCSRC_UCPOL  0
#define UCSRC_UCSZ0  1
#define UCSRC_UCSZ1  2
#define UCSRC_USBS   3
#define UCSRC_UPM0   4
#define UCSRC_UPM1   5
#define UCSRC_UMSEL  6
#define UCSRC_URSEL  7

#define UBBRL    *((volatile u8*)0x29)

#define UBBRH    *((volatile u8*)0x40)
//its bits 
#define UBBRH_URSEL 7

/****************************************************************************************************************/

//UCSRC_UMSEL bit setting
#define SYNCH                                   1
#define ASYNCH                                  0

//UCSRC_UPM  parity mode seting 
#define DISABLED                                0
#define ENABLE_EVEN                             2
#define ENABLE_ODD                              3

//UCSRC_USBS  Stop bit setting
#define ONE_BIT                                 0
#define TWO_BITS                                1

//UCSRC  &   UCSRB  UCSZ[0:2] setting 
#define DATA_SIZE_5_BIT		                    0
#define DATA_SIZE_6_BIT		                    1
#define DATA_SIZE_7_BIT		                    2
#define DATA_SIZE_8_BIT		                    3
#define DATA_SIZE_9_BIT		                    4

//UCSRC_UCPOL  data trans.
#define XCK_RISING_TX_XCH_FALLING_RX			0
#define XCK_RISING_RX_XCH_FALLING_TX			1

#define USART_X1			                    1
#define USART_X2			                    2


#endif
