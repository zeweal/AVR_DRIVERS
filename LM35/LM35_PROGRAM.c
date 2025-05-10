/*
***************************************************************LM35_PROGRAM.c*************************************************************************
Author : Abdallah Zeweal
Layer : HAL
SWC : LM35
*/
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"ADC_INTERFACE.h"

#include"LM35_INTERFACE.h"
#include"LM35_PRIVATE.h"
#include"LM35_CINFIG.h"


u8 GET_TEMP(LM35_CONFIG * lm35 , u8 * Copy_u8TempValue){
	
	u8 Local_u8ErrorState = OK ;
	u16 Local_u16ADCResult ;
	u16 Local_u16AnalogValue ;
	
	u16 Local_u16ADCRefrence=(lm35->Copy_u8ADCVoltageReference)*1000  ;//(mv)
	GET_RESULT_SUNC(lm35->Copy_u8LM35Channel,&Local_u16ADCResult);
	if ( lm35->Copy_u8ADCResolution == ADC_RESOLUTION_10_BIT )
	{
		Local_u16AnalogValue = (u16) ( ((u32)Local_u16ADCResult * (u32)Local_u8ADCReference ) / 1024UL) ;

	}
	else if ( lm35->Copy_u8ADCResolution == ADC_RESOLUTION_8_BIT )
	{
		Local_u16AnalogValue = (u16) ( ((u32)Local_u16ADCResult * (u32)Local_u8ADCReference ) / 256UL) ;
	}


	/* Convert ( mv --> Temp ) */
	* Copy_u8TempValue = Local_u16AnalogValue / 10 ;

	return Local_u8ErrorState ;

}