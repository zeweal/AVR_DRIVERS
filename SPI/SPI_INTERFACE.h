#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#define SPI_INTERRUPT_ENABLE     1
#define SPI_INTERRUPT_DISABLE    0

#define SPI_ENABLE               1
#define SPI_DISABLE              0

#define SPI_MASTER               1
#define SPI_SLAVE                0


#define SPI_RISING_LEADING_FALLING_TRAILING 	0
#define SPI_FALLING_LEADING_RISING_TRAILING		1



#define SPI_SAMPLE_LEADING_SETUP_TRAILING 		0
#define SPI_SETUP_LEADING_SAMPLE_TRAILING		1

#define SPI_LSB_FIRST                           0
#define SPI_MSB_FIRST                           1


#define SPI_FREQ_DIVIDED_BY_2					0
#define SPI_FREQ_DIVIDED_BY_4					1
#define SPI_FREQ_DIVIDED_BY_8					2
#define SPI_FREQ_DIVIDED_BY_16					3
#define SPI_FREQ_DIVIDED_BY_32					4
#define SPI_FREQ_DIVIDED_BY_64					5
#define SPI_FREQ_DIVIDED_BY_128					6

typedef struct{
	u8 SPI_u8Enable;
	u8 SPI_u8InterruptEnable;
	u8 SPI_u8DataOrder;
	u8 SPI_u8MasterSlaveSelect;
	u8 SPI_u8ClockPolarity;
	u8 SPI_u8ClockPhase;
	u8 SPI_u8ClockRate;
}SPI_CONFIG;


typedef struct
{
	u8 * Copy_u8TData ;
	u8 * Copy_u8RData ;
	u8 Copy_u8BufferSize ;
	void(* NotificationFuncn)(void) ;
}SPI_BUFFER;

void SPI_INIT();
u8 SPI_INIT_CONFIG (SPI_CONFIG * spi) ;
u8 SPI_TRANCEIVER (u8 Copy_u8TData , u8 * Copy_u8RData) ;
u8 SPI_BUFFER_TRANCEIVER_SYNCH (u8 * Copy_u8TData , u8 * Copy_u8RData , u8 Copy_u8BufferSize) ;
u8 SPI_BUFFER_TRANCEIVER_ASYNCH(SPI_BUFFER * spi_buffer) ;


#endif
