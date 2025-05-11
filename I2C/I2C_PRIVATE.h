#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_


#define TWBR         *((volatile u8*)0x20)  // selects the division factor for the bit rate generator


#define TWCR         *((volatile u8*)0x56)  // used to control the operation of the TWI
// its bits 
#define TWCR_TWINT        7  // TWI Interrupt Flag
#define TWCR_TWEA         6  // TWI Enable Acknowledge Bit
#define TWCR_TWSTA        5  // TWI START Condition Bit
#define TWCR_TWSTO        4  // TWI STOP Condition Bit
#define TWCR_TWWC         3  // TWI Write Collision Flag
#define TWCR_TWEN         2  // TWI Enable Bit
#define TWCR_TWIE         0  // TWI Interrupt Enable


#define TWSR        *((volatile u8*)0x21) //  TWI Status Register
// its bits 
#define TWSR_TWS7        7  //  These five bits reflect the status of the TWI logic and the Two-wire Serial Bus
#define TWSR_TWS6        6  //  These five bits reflect the status of the TWI logic and the Two-wire Serial Bus
#define TWSR_TWS5        5  //  These five bits reflect the status of the TWI logic and the Two-wire Serial Bus
#define TWSR_TWS4        4  //  These five bits reflect the status of the TWI logic and the Two-wire Serial Bus
#define TWSR_TWS3        3  //  These five bits reflect the status of the TWI logic and the Two-wire Serial Bus
#define TWSR_TWPS1       1  // control the bit rate prescaler.
#define TWSR_TWPS0       0  // control the bit rate prescaler.


#define TWDR       *((volatile u8*)0x23) //  TWI Data Register
// its bits
#define TWD7             7  
#define TWD6             6
#define TWD5             5
#define TWD4             4
#define TWD3             3
#define TWD2             2
#define TWD1             1
#define TWD0             0


#define TWAR     *((volatile u8*)0x22)  // TWI (Slave) Address Register
// its bits 
#define TWAR_TWA6        7 // These seven bits constitute the slave address of the TWI unit.
#define TWAR_TWA5        6 // These seven bits constitute the slave address of the TWI unit.
#define TWAR_TWA4        5 // These seven bits constitute the slave address of the TWI unit.
#define TWAR_TWA3        4 // These seven bits constitute the slave address of the TWI unit.
#define TWAR_TWA2        3 // These seven bits constitute the slave address of the TWI unit.
#define TWAR_TWA1        2 // These seven bits constitute the slave address of the TWI unit.
#define TWAR_TWA0        1 // These seven bits constitute the slave address of the TWI unit.
#define TWAR_TWGCE       0 // enables the recognition of a General Call



#define START_ACK                0x08 /* start has been sent */
#define REP_START_ACK            0x10 /* repeated start */
#define SLAVE_ADD_AND_WR_ACK     0x18 /* Master transmit ( slave address + Write request ) ACK */
#define SLAVE_ADD_AND_RD_ACK     0x40 /* Master transmit ( slave address + Read request ) ACK */
#define MSTR_WR_BYTE_ACK         0x28 /* Master transmit data ACK */
#define MSTR_RD_BYTE_WITH_ACK    0x50 /* Master received data with ACK */
#define MSTR_RD_BYTE_WITH_NACK   0x58 /* Master received data with not ACK */
#define SLAVE_ADD_RCVD_RD_REQ    0xA8 /* means that slave address is received with read request */
#define SLAVE_ADD_RCVD_WR_REQ    0x60 /* means that slave address is received with write request */
#define SLAVE_DATA_RECEIVED      0x80 /* means that a byte is received */
#define SLAVE_BYTE_TRANSMITTED   0xB8 /* means that the written byte is transmitted */


/* Prescalers */
#define PRESCALLER_BY_1    1
#define PRESCALLER_BY_4    4
#define PRESCALLER_BY_16   16
#define PRESCALLER_BY_64   64


#endif