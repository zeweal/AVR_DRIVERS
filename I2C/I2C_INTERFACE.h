#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_



typedef enum
{
	NoError,
	StartConditionError,
	RepeatedStartError,
	SlaveAddressWithWriteError,
	SlaveAddressWithReadError,
	MasterWriteByteError,
	MasterReadByteError,
	SlaveWriteByteError,
	SlaveReadByteError,	
}TWI_ErrorStatus;


TWI_ErrorStatus TWI_INIT_MASTER(u8 Copy_u8Address);
TWI_ErrorStatus TWI_INIT_SLAVE(u8 Copy_u8Address); 
TWI_ErrorStatus TWI_SEND_START(void);
TWI_ErrorStatus TWI_SEND_REPEATED_START(void);
TWI_ErrorStatus TWI_SEND_SLAVE_ADD_WITH_WRITE(u8 Copy_u8Address);
TWI_ErrorStatus TWI_SEND_SLAVE_ADD_WITH_READ(u8 Copy_u8Address);
TWI_ErrorStatus TWI_MASTER_WRITE_DATA_BYTE(u8 Copy_u8DataByte);
TWI_ErrorStatus TWI_MASTER_READ_DATA_BYTE(u8* Copy_u8DataByte);
TWI_ErrorStatus TWI_SLAVE_WRITE_DATA_BYTE(u8 Copy_u8DataByte);
TWI_ErrorStatus TWI_SEND_STOP(void);


#endif