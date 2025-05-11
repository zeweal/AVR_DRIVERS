#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"SPI_PRIVATE.h"
#include"SPI_CONFIG.h"
#include"SPI_INTERFACE.h"


static u8 SPI_STATE = IDLE;
static void (* SPI_pvNotificationFunc)(void)= NULL;
static u8 * SPI_pu8TData = NULL ;
static u8 * SPI_pu8RData = NULL ;
static u8 SPI_u8BufferSize;
static u8 SPI_u8Index;



void SPI_INIT(){
	#if SPI_ENABLE_MODE  ==  SPI_ENABLE 
	     SET_BIT(SPCR_SPE,SPCR);
	#elif SPI_ENABLE_MODE  ==  SPI_DISABLE
	     CLR_BIT(SPCR_SPE,SPCR);
	#endif
	
	#if SPI_INTERRUPT_ENABLE_MODE  == SPI_INTERRUPT_ENABLE
	      SET_BIT(SPCR_SPIE,SPCR);
	#elif SPI_INTERRUPT_ENABLE_MODE  == SPI_INTERRUPT_DISABLE
	      CLR_BIT(SPCR_SPIE,SPCR);
	#endif
	
	#if SPI_DATA_ORDER == SPI_LSB_FIRST
	    SET_BIT(SPCR_DODR,SPCR);
	#elif SPI_DATA_ORDER == SPI_MSB_FIRST
	    CLR_BIT(SPCR_DODR,SPCR);
	#endif
	
	#if MASTER_SLAVE_SELECT == SPI_MASTER
	    SET_BIT(SPCR_MSTR,SPCR);
	#elif MASTER_SLAVE_SELECT == SPI_SLAVE
	    CLR_BIT(SPCR_MSTR,SPCR);
	#endif
	
	#if SPI_CLOCK_POLARITY  == SPI_RISING_LEADING_FALLING_TRAILING
	     CLR_BIT(SPCR_CPOL,SPCR);
    #elif SPI_CLOCK_POLARITY == SPI_FALLING_LEADING_RISING_TRAILING
	     SET_BIT(SPCR_CPOL,SPCR);
	#endif

    #if SPI_CLOCK_PHASE == SPI_SAMPLE_LEADING_SETUP_TRAILING	
	     CLR_BIT(SPCR_CPHA,SPCR);
	#elif SPI_CLOCK_PHASE == SPI_SETUP_LEADING_SAMPLE_TRAILING
	     SET_BIT(SPCR_CPHA,SPCR);
	#endif
	
	#if SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_4
	      CLR_BIT(SPCR_SPR1,SPCR);
		  CLR_BIT(SPCR_SPR0,SPCR);
	      CLR_BIT(SPSR_SPI2X,SPSR);
	#elif SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_16
	      CLR_BIT(SPCR_SPR1,SPCR);
		  SET_BIT(SPCR_SPR0,SPCR);
	      CLR_BIT(SPSR_SPI2X,SPSR);
	#elif SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_64
	      SET_BIT(SPCR_SPR1,SPCR);
		  CLR_BIT(SPCR_SPR0,SPCR);
	      CLR_BIT(SPSR_SPI2X,SPSR);
	#elif SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_128
	      SET_BIT(SPCR_SPR1,SPCR);
		  SET_BIT(SPCR_SPR0,SPCR);
	      CLR_BIT(SPSR_SPI2X,SPSR);
	#elif SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_2
	      CLR_BIT(SPCR_SPR1,SPCR);
		  CLR_BIT(SPCR_SPR0,SPCR);
	      SET_BIT(SPSR_SPI2X,SPSR);
	#elif SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_8
	      CLR_BIT(SPCR_SPR1,SPCR);
		  SET_BIT(SPCR_SPR0,SPCR);
	      SET_BIT(SPSR_SPI2X,SPSR);
	#elif SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_32
	      SET_BIT(SPCR_SPR1,SPCR);
		  CLR_BIT(SPCR_SPR0,SPCR);
	      SET_BIT(SPSR_SPI2X,SPSR);
	#endif 
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

u8 SPI_INIT_CONFIG (SPI_CONFIG * spi){
	u8 LOC = OK;
    if(spi != NULL) {
	switch(spi->SPI_u8InterruptEnable){
		case SPI_INTERRUPT_ENABLE:                                             SET_BIT(SPCR_SPIE,SPCR);   break;
		case SPI_INTERRUPT_DISABLE:                                            CLR_BIT(SPCR_SPIE,SPCR);   break;

	}                                                                          
	switch(spi->SPI_u8Enable){
		case SPI_ENABLE:                                                       SET_BIT(SPCR_SPE,SPCR);   break;
        case SPI_DISABLE:                                                      CLR_BIT(SPCR_SPE,SPCR);   break;

	}                                                                          
	switch(spi->SPI_u8DataOrder){
		case SPI_LSB_FIRST:                                                    SET_BIT(SPCR_DODR,SPCR);  break;
		case SPI_MSB_FIRST:                                                    CLR_BIT(SPCR_DODR,SPCR);  break;
	}                                                                          
	switch(spi->SPI_u8MasterSlaveSelect){
		case SPI_MASTER:                                                       SET_BIT(SPCR_MSTR,SPCR);  break;
		case SPI_SLAVE:                                                        CLR_BIT(SPCR_MSTR,SPCR);  break;
	}
	switch(spi->SPI_u8ClockPolarity){
		case SPI_RISING_LEADING_FALLING_TRAILING :                             CLR_BIT(SPCR_CPOL,SPCR); break;
		case SPI_FALLING_LEADING_RISING_TRAILING :                             SET_BIT(SPCR_CPOL,SPCR); break;
	}
	switch(spi->SPI_u8ClockPhase){
		case SPI_SAMPLE_LEADING_SETUP_TRAILING :                               CLR_BIT(SPCR_CPHA,SPCR); break;
		case SPI_SETUP_LEADING_SAMPLE_TRAILING :                               SET_BIT(SPCR_CPHA,SPCR); break;
	}
	switch(spi->SPI_u8ClockRate){
		case SPI_FREQ_DIVIDED_BY_4 :                                           CLR_BIT(SPCR_SPR1,SPCR);    
	                                                                          CLR_BIT(SPCR_SPR0,SPCR);
	                                                                           CLR_BIT(SPSR_SPI2X,SPSR);
																			   break;
	    case SPI_FREQ_DIVIDED_BY_16 :                                          CLR_BIT(SPCR_SPR1,SPCR);
	                                                                           SET_BIT(SPCR_SPR0,SPCR);
	                                                                           CLR_BIT(SPSR_SPI2X,SPSR);
																			   break;
		case SPI_FREQ_DIVIDED_BY_64 :                                          SET_BIT(SPCR_SPR1,SPCR);
	                                                                           CLR_BIT(SPCR_SPR0,SPCR);
	                                                                           CLR_BIT(SPSR_SPI2X,SPSR);
																			   break;
		case SPI_FREQ_DIVIDED_BY_128 :                                         SET_BIT(SPCR_SPR1,SPCR);
																			   SET_BIT(SPCR_SPR0,SPCR);
																			   CLR_BIT(SPSR_SPI2X,SPSR);
																			   break;
	    case SPI_FREQ_DIVIDED_BY_2 :                                           CLR_BIT(SPCR_SPR1,SPCR);
	                                                                           CLR_BIT(SPCR_SPR0,SPCR);
	                                                                           SET_BIT(SPSR_SPI2X,SPSR);
																			   break;
		case SPI_FREQ_DIVIDED_BY_8 :                                           CLR_BIT(SPCR_SPR1,SPCR);
		                                                                       SET_BIT(SPCR_SPR0,SPCR);
		                                                                       SET_BIT(SPSR_SPI2X,SPSR);
																			   break;
		case SPI_FREQ_DIVIDED_BY_32 :                                          SET_BIT(SPCR_SPR1,SPCR);
																			   CLR_BIT(SPCR_SPR0,SPCR);
		                                                                       SET_BIT(SPSR_SPI2X,SPSR);
																			   break;
	}
		
    }
    else{
		LOC = NOK;
	} 	
	return LOC;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
u8 SPI_TRANCEIVER (u8 Copy_u8TData , u8 * Copy_u8RData) {
	u8 ERROR = OK;
	u8 LOCAL_TIMER =0;
	if(SPI_STATE == IDLE){
		SPI_STATE = BUSY;
		SPDR = Copy_u8TData ;
		while((GET_BIT(SPSR_SPIF,SPSR)) && (LOCAL_TIMER < TIMEOUT) ){
			LOCAL_TIMER ++;
		}
		if(LOCAL_TIMER == TIMEOUT){
			ERROR = TIMEOUT_STATE;
		}
		else{
			* Copy_u8RData = SPDR;
		}
		SPI_STATE = IDLE;
	}
	else{
		ERROR= BUSY_STATE;
	}
	return ERROR;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
u8 SPI_BUFFER_TRANCEIVER_SYNCH (u8 * Copy_u8TData , u8 * Copy_u8RData , u8 Copy_u8BufferSize) {
	u8 ERROR = OK;
	u8 LOCAL_BUFFER = 0;
	if(SPI_STATE == IDLE){
		SPI_STATE = BUSY;
		if((* Copy_u8TData != NULL) && (* Copy_u8RData != NULL)){
			while(LOCAL_BUFFER < Copy_u8BufferSize){
			 SPI_TRANCEIVER(Copy_u8TData[LOCAL_BUFFER],Copy_u8RData[LOCAL_BUFFER]);
             LOCAL_BUFFER++;			 
			}
		}
		else{
			ERROR= NULL_POINTER;
		}
	}
	else{
		ERROR = BUSY_STATE;
	}
	return ERROR;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
u8 SPI_BUFFER_TRANCEIVER_ASYNCH(SPI_BUFFER * spi_buffer) {
	u8 ERROR = OK;
	if(SPI_STATE == IDLE){
		SPI_STATE = BUSY; 
		if((spi_buffer->Copy_u8TData != NULL) && (spi_buffer->Copy_u8RData != NULL) && (spi_buffer != NULL) && (spi_buffer->NotificationFuncn != NULL)){
		           SPI_pu8TData=spi_buffer->Copy_u8TData;
				   SPI_pu8RData=spi_buffer->Copy_u8RData;
				   SPI_pvNotificationFunc=spi_buffer->NotificationFuncn;
				   SPI_u8BufferSize=spi_buffer->Copy_u8BufferSize;
				   
				   SPI_u8Index=0;
				   SPDR=SPI_pu8TData[SPI_u8Index];
				   SET_BIT(SPCR_SPE,SPCR);
				   SPI_STATE=IDLE;
		}
		else{
			ERROR = NULL_POINTER;
		}
	}
	else{
		ERROR= BUSY_STATE;
	}
	return ERROR;
}	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void __vector_12 (void)                                __attribute__ ((signal));
void __vector_12 (void)
{
SPI_pu8RData[SPI_u8Index] = SPDR ;
	SPI_u8Index++ ;

	if (SPI_u8Index == SPI_u8BufferSize)
	{
		SPI_STATE = IDLE ;
		CLR_BIT(SPCR_SPIE,SPCR) ;
		SPI_pvNotificationFunc() ;
	}
	else
	{
		SPDR = SPI_pu8TData[SPI_u8Index] ;
	}
}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
