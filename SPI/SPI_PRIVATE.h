#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define SPCR             *((volatile u8*)0x2D)
// its bits 
#define SPCR_SPIE       7    // SPI interrupt enable
#define SPCR_SPE        6    // SPI Enable
#define SPCR_DODR       5     // data order
#define SPCR_MSTR       4     // master slave select
#define SPCR_CPOL       3      // clock polarity 
#define SPCR_CPHA       2      // clock phase
#define SPCR_SPR1       1      // clock rate select
#define SPCR_SPR0       0      // clock rate select


#define SPSR             *((volatile u8*)0x2E)
// its bits
#define SPSR_SPIF       7    // SPI interrupt flag
#define SPSR_WCOL       6    // SPI write collision flag
#define SPSR_SPI2X      0    // double speed rate


#define SPDR             *((volatile u8*)0x2F)
// its bits 
#define SPDR_MSB        7
#define SPDR_LSB        0

#endif