#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"I2C_INTERFACE.h"
#include"I2C_PRIVATE.h"
#include"I2C_CONFIG.h"



TWI_ErrorStatus TWI_INIT_MASTER(u8 Copy_u8Address){
    TWBR = (u8) (((CPU_FREQ / SCL_Clock)-16) / (2*TWI_PRESCALLER));
	
	if(TWI_PRESCALLER == PRESCALLER_BY_1){
		TWSR = 0;
	}
	else if (TWI_PRESCALLER == PRESCALLER_BY_4){
		TWSR = 1;
	}
	else if (TWI_PRESCALLER == PRESCALLER_BY_16){
		TWSR = 2;
	}
	else if (TWI_PRESCALLER == PRESCALLER_BY_64){
		TWSR = 3;
	}
	
	// address of slave 
	if(Copy_u8Address != 0){
		TWAR = (Copy_u8Address <<1);
	}
	else{
		#error
	}
	// set ack
	SET_BIT(TWCR_TWEA,TWCR);
	SET_BIT(TWCR_TWEN,TWCR);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
TWI_ErrorStatus TWI_INIT_SLAVE(u8 Copy_u8Address){
	TWAR = (Copy_u8Address <<1);
	SET_BIT(TWCR_TWEA,TWCR);
	SET_BIT(TWCR_TWEN,TWCR);
	
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
TWI_ErrorStatus TWI_SEND_START(void){
	TWI_ErrorStatus LOC_ERROR= NoError;
	SET_BIT(TWCR_TWSTA,TWCR);
	SET_BIT(TWCR_TWINT,TWCR);
	while(GET_BIT(TWCR_TWINT,TWCR) == 0);
		if((TWSR & 0xF8) != START_ACK ){
			LOC_ERROR = StartConditionError;
		}
	return LOC_ERROR;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
TWI_ErrorStatus TWI_SEND_REPEATED_START(void){
	TWI_ErrorStatus LOC_ERROR= NoError;
	SET_BIT(TWCR_TWSTA,TWCR);
	SET_BIT(TWCR_TWINT,TWCR);
	while(GET_BIT(TWCR_TWINT,TWCR) == 0);
		if((TWSR & 0xF8) != REP_START_ACK ){
			LOC_ERROR = StartConditionError;
		}
	return LOC_ERROR;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
TWI_ErrorStatus TWI_SEND_SLAVE_ADD_WITH_WRITE(u8 Copy_u8Address){
	TWI_ErrorStatus LOC_ERROR= NoError;
	TWDR = (Copy_u8Address <<1);
	CLR_BIT(0,TWDR);
	CLR_BIT(TWCR_TWSTA,TWCR);
	SET_BIT(TWCR_TWINT,TWCR);
	while(GET_BIT(TWCR_TWINT,TWCR) == 0);
		if((TWSR & 0xF8) != SLAVE_ADD_AND_WR_ACK ){
			LOC_ERROR = SlaveAddressWithWriteError;
		}
	return LOC_ERROR;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TWI_ErrorStatus TWI_SEND_SLAVE_ADD_WITH_READ(u8 Copy_u8Address){
	TWI_ErrorStatus LOC_ERROR= NoError;
	TWDR = (Copy_u8Address <<1);
	SET_BIT(0,TWDR);
	CLR_BIT(TWCR_TWSTA,TWCR);
	SET_BIT(TWCR_TWINT,TWCR);
	while(GET_BIT(TWCR_TWINT,TWCR) == 0);
		if((TWSR & 0xF8) != SLAVE_ADD_AND_RD_ACK ){
			LOC_ERROR = SlaveAddressWithReadError;
		}
	return LOC_ERROR;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TWI_ErrorStatus TWI_MASTER_WRITE_DATA_BYTE(u8 Copy_u8DataByte){
	TWI_ErrorStatus LOC_ERROR= NoError;
	TWDR = Copy_u8DataByte ;
	SET_BIT(TWCR_TWINT,TWCR);
	while(GET_BIT(TWCR_TWINT,TWCR) == 0);
		if((TWSR & 0xF8) != MSTR_WR_BYTE_ACK ){
			LOC_ERROR = MasterWriteByteError;
		}
	return LOC_ERROR;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TWI_ErrorStatus TWI_MASTER_READ_DATA_BYTE(u8* Copy_u8DataByte){
	TWI_ErrorStatus LOC_ERROR= NoError;
	SET_BIT(TWCR_TWINT,TWCR);
	while(GET_BIT(TWCR_TWINT,TWCR) == 0);
		if((TWSR & 0xF8) != MSTR_RD_BYTE_WITH_ACK ){
			LOC_ERROR = MasterReadByteError;
		}
		else{
		 *Copy_u8DataByte = TWDR ;
		}
	return LOC_ERROR;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TWI_ErrorStatus TWI_SLAVE_WRITE_DATA_BYTE(u8 Copy_u8DataByte){
	TWI_ErrorStatus LOC_ERROR= NoError;
	TWDR = Copy_u8DataByte ;
	SET_BIT(TWCR_TWINT,TWCR);
	while(GET_BIT(TWCR_TWINT,TWCR) == 0);
		if((TWSR & 0xF8) != SLAVE_BYTE_TRANSMITTED ){
			LOC_ERROR = SlaveWriteByteError;
		}
	return LOC_ERROR;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TWI_ErrorStatus TWI_SLAVE_WRITE_DATA_BYTE(u8 *Copy_u8DataByte){
	TWI_ErrorStatus LOC_ERROR= NoError;
	SET_BIT(TWCR_TWINT,TWCR);
	while(GET_BIT(TWCR_TWINT,TWCR) == 0);
		if((TWSR & 0xF8) != SLAVE_ADD_RCVD_WR_REQ ){
			LOC_ERROR = SlaveReadByteError;
		}
	SET_BIT(TWCR_TWINT,TWCR);
	while(GET_BIT(TWCR_TWINT,TWCR) == 0);
		if((TWSR & 0xF8) != SLAVE_DATA_RECEIVED ){
			LOC_ERROR = SlaveReadByteError;
		}
		else{
			*Copy_u8DataByte = TWDR ;
		}
	
	return LOC_ERROR;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TWI_ErrorStatus TWI_SEND_STOP(void){
	SET_BIT(TWCR_TWSTO,TWCR);
	SET_BIT(TWCR_TWINT,TWCR);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




















