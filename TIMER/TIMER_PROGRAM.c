/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    TIMER_PROGRAM.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Abdallah Zeweal
 *  Layer  : MCAL
 *  SWC    : TIMER
 *
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"TIMER_INTERFACE.h"
#include"TIMER_CONFIG.h"
#include"TIMER_PRIVATE.h"
#include"DIO_INTERFACE.h"
//#include"EXTERNAL_INTERFACE.h"
 
 
 static void (*TIMERS_pvCallBackFunc[16])(void) = {NULL} ; 

//***************************************************************TIMER0*******************************************************************************

 void TIMER0_INIT(void){
	 #if TIMER0_WAVEFORM_GENERATION_MODE == TIMER_NORMAL_MODE
	     CLR_BIT(TCCR0,TCCR0_WGM00);
		 CLR_BIT(TCCR0,TCCR0_WGM01);

		//set overflow intrupt
		#if TIMER0_OVERFLOW_INTERUPT == ENABLE
		   SET_BIT(TIMSK,TIMSK_TOIE0);
		#elif TIMER0_OVERFLOW_INTERUPT == DISABLE
		   CLR_BIT(TIMSK_TOIE0,TIMSK);
		#endif
		   //set preload value
		   		TCNT0= TIMER0_PRELOAD_VALUE;
		
	 #elif TIMER0_WAVEFORM_GENERATION_MODE == TIMER_PWM_MODE
	     SET_BIT(TCCR0_WGM00,TCCR0);
		 CLR_BIT(TCCR0_WGM01,TCCR0);
		 DIO_SET_PIN_DIRECTION(DIO_PORTB,DIO_PIN4,DIO_PIN_OUTPUT);
		 // Set CTC PWM Mode
		 #if TIMER0_CTC_PWM_MODE == TIMER_OC_DISCONNECTED
		  CLR_BIT(TCCR0_COM00,TCCR0);
		  CLR_BIT(TCCR0_COM01,TCCR0);
		#elif TIMER0_CTC_PWM_MODE == TIMER_CLR_ON_CTC_SET_ON_TOP
		  CLR_BIT(TCCR0_COM00,TCCR0);
		  SET_BIT(TCCR0_COM01,TCCR0);
		#elif TIMER0_CTC_PWM_MODE == TIMER_SET_ON_CTC_CLR_ON_TOP
		  SET_BIT(TCCR0_COM01,TCCR0);
		  SET_BIT(TCCR0_COM00,TCCR0);
		#else 
			#error
		#endif 
	
	#elif TIMER0_WAVEFORM_GENERATION_MODE == TIMER_CTC_MODE
	     SET_BIT(TCCR0_WGM01,TCCR0);
		 CLR_BIT(TCCR0_WGM00,TCCR0);
		
		//set overflow intrupt
		#if TIMER0_CTC_INTERRUPT == ENABLE
		  SET_BIT(TIMSK_OCIE0,TIMSK);
		#elif TIMER0_CTC_INTERRUPT == DISABLE
		  CLR_BIT(TIMSK_OCIE0,TIMSK);	 
		#endif
#if TIMER0_OC == CTC_OC_TOGGEL
	CLR_BIT(TCCR0,TCCR0_COM01);
	SET_BIT(TCCR0,TCCR0_COM00);
#elif 	TIMER0_OC == CTC_OC_DISCONNECT
	CLR_BIT(TCCR0,TCCR0_COM01);
	CLR_BIT(TCCR0,TCCR0_COM00);
#elif TIMER0_OC == CTC_OC_CLEAR
	SET_BIT(TCCR0,TCCR0_COM01);
	CLR_BIT(TCCR0,TCCR0_COM00);

#elif 	TIMER0_OC == CTC_OC_SET
	SET_BIT(TCCR0,TCCR0_COM01);
	SET_BIT(TCCR0,TCCR0_COM00);

#endif
	OCR0=TIMER0_CTC_VALUE;
		
	#elif TIMER0_WAVEFORM_GENERATION_MODE == TIMER_FAST_PWM_MODE
	    SET_BIT(TCCR2_WGM10,TCCR0);
	    SET_BIT(TCCR2_WGM00,TCCR0);
		DIO_SET_PIN_DIRECTION(DIO_PORTB,DIO_PIN4,DIO_PIN_OUTPUT);
		
		/*Set CTC Fast PWM MODE*/
			#if TIMER0_CTC_PWM_MODE == TIMER_OC_DISCONNECTED
					CLR_BIT(TCCR0_COM00,TCCR0) ;
					CLR_BIT(TCCR0_COM01,TCCR0) ;
			#elif TIMER0_CTC_PWM_MODE == TIMER_CLR_ON_CTC_SET_ON_TOP
					CLR_BIT(TCCR0_COM00,TCCR0) ;
					SET_BIT(TCCR0_COM01,TCCR0) ;
			#elif TIMER0_CTC_PWM_MODE == TIMER_SET_ON_CTC_CLR_ON_TOP
					SET_BIT(TCCR0_COM00,TCCR0) ;
					SET_BIT(TCCR0_COM01,TCCR0) ;
			#else
					#error "Wrong TIMER0_CTC_PWM_MODE Config"
			#endif

			/*Set the Required CTC Value*/
					OCR0 = TIMER0_CTC_VAL ;
           #else
                #error
		
	#endif
		
	TCCR0 &=TIMER_PRESCALER_MASK;
	TCCR0 |= TIMER0_PRESCALLER;
 }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void TIMER0_SET_PRELOAD(u8 Copy_u8Preload){
	 TCNT0= Copy_u8Preload;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void TIMER0_SET_CTC(u8 Copy_u8CTC){
	OCR0= Copy_u8CTC ;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
u8 TIMER0_GET_COUNTER_VALUE(void){
	return TCNT0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//**********************************************************************TIMER2************************************************************************************
void TIMER2_INIT(void){

	#if TIMER2_WAVEFORM_GENERATION_MODE == TIMER_NORMAL_MODE     //
	CLR_BIT(TCCR2_WGM20,TCCR2);
	CLR_BIT(TCCR2_WGM21,TCCR2);
	
	#if TIMER2_OVERFLOW_INTERUPT ==ENABLE
	SET_BIT(TIMSK_TOIE2,TIMSK);
	#elif TIMER2_OVERFLOW_INTERUP == DISABLE
	CLR_BIT(TIMSK_TOIE2,TIMSK);
	#endif
	TCNT2= TIMER2_PRELOAD_VALUE;
	
	#elif TIMER2_WAVEFORM_GENERATION_MODE ==TIMER_CTC_MODE      //
	CLR_BIT(TCCR2,TCCR2_WGM20);
	SET_BIT(TCCR2,TCCR2_WGM21);

#if TIMER2_OC2_MODE== TIMER_OC_TOGGEL
				CLR_BIT(TCCR2,TCCR2_COM21);
				SET_BIT(TCCR2,TCCR2_COM20);
			#elif 	TIMER2_OC2_MODE == TIMER_OC_DISCONNECTED
				CLR_BIT(TCCR2,TCCR2_COM21);
				CLR_BIT(TCCR2,TCCR2_COM20);
			#elif TIMER2_OC2_MODE == TIMER_OC_CLEAR
				SET_BIT(TCCR2_COM21,TCCR2);
				CLR_BIT(TCCR2_COM20,TCCR2);

			#elif 	TIMER2_OC2_MODE == TIMER_OC_SET
				SET_BIT(TCCR2_COM21,TCCR2);
				SET_BIT(TCCR2_COM20,TCCR2);

			#endif

	OCR2= TIMER2_CTC_VALUE ;
	
	#if TIMER2_CTC_INTERRUPT == ENABLE
	SET_BIT(TIMSK,TIMSK_OCIE2);
	#elif TIMER2_CTC_INTERRUPT == DISABLE
		CLR_BIT(TIMSK_OCIE2,TIMSK);
    #endif
	#elif TIMER2_WAVEFORM_GENERATION_MODE == TIMER_PWM_MODE    //
	CLR_BIT(TCCR2_WGM21,TCCR2);
	SET_BIT(TCCR2_WGM20,TCCR2);
	DIO_SET_PIN_DIRECTION(DIO_PORTD,DIO_PIN7,DIO_PIN_OUTPUT);
	
	    /*Set CTC PWM MODE*/
	    #if TIMER2_CTC_PWM_MODE == TIMER_OC_DISCONNECTED
					CLR_BIT(TCCR2_COM20,TCCR2) ;
					CLR_BIT(TCCR2_COM21,TCCR2) ;
			#elif TIMER2_CTC_PWM_MODE == TIMER_CLR_ON_CTC_SET_ON_TOP
					CLR_BIT(TCCR2_COM20,TCCR2) ;
					SET_BIT(TCCR2_COM21,TCCR2) ;
			#elif TIMER2_CTC_PWM_MODE == TIMER_SET_ON_CTC_CLR_ON_TOP
					SET_BIT(TCCR2_COM20,TCCR2) ;
					SET_BIT(TCCR2_COM21,TCCR2) ;
			#else
					#error "Wrong TIMER2_CTC_PWM_MODE Config"
			#endif
	OCR2 =TIMER2_CTC_VALUE;
	
	#elif TIMER2_WAVEFORM_GENERATION_MODE == TIMER_FAST_PWM_MODE   //
	SET_BIT(TCCR2_WGM21,TCCR2);
	SET_BIT(TCCR2_WGM20,TCCR2);
	DIO_SET_PIN_DIRECTION(DIO_PORTD,DIO_PIN7,DIO_PIN_OUTPUT);
	
	    #if TIMER2_CTC_PWM_MODE == TIMER_OC_DISCONNECTED
					CLR_BIT(TCCR2_COM20,TCCR2) ;
					CLR_BIT(TCCR2_COM21,TCCR2) ;
			#elif TIMER2_CTC_PWM_MODE == TIMER_CLR_ON_CTC_SET_ON_TOP
					CLR_BIT(TCCR2_COM20,TCCR2) ;
					SET_BIT(TCCR2_COM21,TCCR2) ;
			#elif TIMER2_CTC_PWM_MODE == TIMER_SET_ON_CTC_CLR_ON_TOP
					SET_BIT(TCCR2_COM20,TCCR2) ;
					SET_BIT(TCCR2_COM21,TCCR2) ;
			#else
					#error "Wrong TIMER2_CTC_PWM_MODE Config"
			#endif
    OCR2 =TIMER2_CTC_VALUE;
	
	#endif
	TCCR2 &=TIMER_PRESCALER_MASK;
	TCCR2 |= TIMER2_PRESCALLER;

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void TIMER2_SET_PRELOAD(u8 Copy_u8Preload){
	TCNT2 = Copy_u8Preload;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void TIMER2_SET_CTC(u8 Copy_u8CTC){
	OCR2= Copy_u8CTC;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
u8 TIMER2_GET_COUNTER_VALUE(void){
	return TCNT2;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////*********ICU_FUNCTIONS*********//////////////////////////////////////////////////////////////////////////////////////

 void TIMER_ICU_INIT_ENABLE(){
     	 
 }


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

u8 TIMER_u8SetCallBack(void (*Copy_pvCallBackFunc)(void) , u8 Copy_u8VectorID)
{
	u8 Local_u8ErrorState = OK ;

	if (Copy_pvCallBackFunc != NULL)
	{
		TIMERS_pvCallBackFunc[Copy_u8VectorID] = Copy_pvCallBackFunc ;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER ;
	}

	return Local_u8ErrorState ;
}

/*TIMER0 Normal Mode ISR*/
void __vector_11 (void)		__attribute__((signal)) ;
void __vector_11 (void)
{
	if (TIMERS_pvCallBackFunc[TIMER0_OVF_VECTOR_ID] != NULL)
	{
		TIMERS_pvCallBackFunc[TIMER0_OVF_VECTOR_ID]() ;
	}
}

/*TIMER0 CTC Mode ISR*/
void __vector_10 (void)		__attribute__((signal)) ;
void __vector_10 (void)
{
	if (TIMERS_pvCallBackFunc[TIMER0_CTC_VECTOR_ID] != NULL)
	{
		TIMERS_pvCallBackFunc[TIMER0_CTC_VECTOR_ID]() ;
	}
}



/* Timer 2 overflow ISR*/

void __vector_5 (void)   __attribute__((signal));
void __vector_5 (void)
{
if(TIMERS_pvCallBackFunc[TIMER2_OVF_VECTOR_ID] != NULL){
	TIMERS_pvCallBackFunc[TIMER2_OVF_VECTOR_ID]();
}
}
/* Timer2 CTC mode*/
void __vector_4 (void)  __attribute__((signal));
void __vector_4 (void)
{
if(TIMERS_pvCallBackFunc[TIMER2_CTC_VECTOR_ID] != NULL){
 TIMERS_pvCallBackFunc[TIMER2_CTC_VECTOR_ID]();	
}
}
