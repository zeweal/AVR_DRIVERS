#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"DIO_INTERFACE.h"
#include"SPI_INTERFACE.h"

#include"CAN_INTERFACE.h"
#include"CAN_PRIVATE.h"
#include"CAN_CONFIG.h"

//     DIO_SET_PIN_VALUE(DIO_PORTB,DIO_PIN4,DIO_PIN_HIGH);
u8 BUS;

u8 CAN_u8ReadRegister(u8 Copy_u8Address){
	u8 readval;
	DIO_SET_PIN_VALUE(DIO_PORTB,DIO_PIN4,DIO_PIN_LOW);
	SPI_TRANCEIVER (INSTRUCTION_FORMAT_READ , &BUS) ;
	readval = SPI_TRANCEIVER (0 , Copy_u8Address) ;
	DIO_SET_PIN_VALUE(DIO_PORTB,DIO_PIN4,DIO_PIN_HIGH);
	return readval;
}

void CAN_WriteRegister(u8 Copy_u8Address,u8 Copy_u8Value){
    DIO_SET_PIN_VALUE(DIO_PORTB,DIO_PIN4,DIO_PIN_LOW);
	SPI_TRANCEIVER (INSTRUCTION_FORMAT_WRITE , &BUS) ;
	SPI_TRANCEIVER (Copy_u8Address , &BUS) ;
	SPI_TRANCEIVER (Copy_u8Value , &BUS) ;
	DIO_SET_PIN_VALUE(DIO_PORTB,DIO_PIN4,DIO_PIN_HIGH);
}

void CAN_ResetRegister(void){
	DIO_SET_PIN_VALUE(DIO_PORTB,DIO_PIN4,DIO_PIN_LOW);
	SPI_TRANCEIVER (INSTRUCTION_FORMAT_RESET , &BUS) ;
	DIO_SET_PIN_VALUE(DIO_PORTB,DIO_PIN4,DIO_PIN_HIGH);
}

void CAN_ModifyRegister(u8 Copy_u8Address,u8 Copy_u8Mask,u8 Copy_u8Value){
	DIO_SET_PIN_VALUE(DIO_PORTB,DIO_PIN4,DIO_PIN_LOW);
	SPI_TRANCEIVER (INSTRUCTION_FORMAT_MODIFY , &BUS) ;
	SPI_TRANCEIVER (Copy_u8Address , &BUS) ;
	SPI_TRANCEIVER (Copy_u8Mask , &BUS) ;
	SPI_TRANCEIVER (Copy_u8Value , &BUS) ;
	DIO_SET_PIN_VALUE(DIO_PORTB,DIO_PIN4,DIO_PIN_HIGH);
} 

void CAN_SetBitTiming(u8 CNF1_VAL,u8 CNF2_VAL,u8 CNF3_VAL){
	CAN_WriteRegister(CNF1,CNF1_VAL);
	CAN_WriteRegister(CNF2,CNF2_VAL);
	CAN_WriteRegister(CNF3,CNF3_VAL);
}

void CAN_SetMode(u8 Copy_u8Mode){
	CAN_ModifyRegister(CANCTRL,0xE0,(mode << 5));
	while(CAN_u8ReadRegister(CANSTAT >> 5 ) != mode);
}

void CAN_INIT(void){
	SPI_INIT();
	CAN_ResetRegister(void);
	// enter config mode and enable clock
	CAN_WriteRegister(CANCTRL,0x84);
	while(CAN_u8ReadRegister(CANSTAT >> 5 ) != CAN_MODE_CONFIG);
	CAN_SetBitTiming(0x80,0xB1,0x05);
	CAN_SetMode(CAN_NORMAL_MODE);
}

void CAN_SEND_MSG(u8 BUFFER_ID,u8 MSG_ID,u8 DLC,u8* DATA){
	DIO_SET_PIN_VALUE(DIO_PORTB,DIO_PIN4,DIO_PIN_LOW);
	SPI_TRANCEIVER(INSTRUCTION_FORMAT_WRITE,&BUS);
	
}


















