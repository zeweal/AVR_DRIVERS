/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    TIMER_INTERFACE.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Abdallah Zeweal
 *  Layer  : MCAL
 *  SWC    : TIMER
 *
 */
 #ifndef TIMER_INTERFACE_H_
 #define TIMER_INTERFACE_H_
 
 


	#define FALLING_EDGE				                    0
	#define RISING_EDGE					                    1
	

	#define TIMER_OC_DISCONNECTED					        0
	#define TIMER_OC_TOGGEL							        1
	#define TIMER_OC_LOW							        2
	#define TIMER_OC_HIGH							        3

	#define TIMER_OC_DISCONNECTED					        0
	#define TIMER_CLR_ON_CTC_SET_ON_TOP				        2
	#define TIMER_SET_ON_CTC_CLR_ON_TOP				        3



 //*********************************************************TIMER0**********************************************************************************
 
 /* Define indexes for the global pointer to func for ISR  */

	#define TIMER0_OVF_VECTOR_ID		11
	#define TIMER0_CTC_VECTOR_ID		10
	
//timer0 functions 
void TIMER0_INIT(void);
void TIMER0_SET_PRELOAD(u8 Copy_u8Preload);
void TIMER0_SET_CTC(u8 Copy_u8CTC);
u8 TIMER0_GET_COUNTER_VALUE(void);


//////////////////////////////////////////////////////////////////////////////////////////

//*********************************************************TIMER2********************************************************************

/* Define indexes for the global pointer to func for ISR  */
    #define TIMER2_OVF_VECTOR_ID		5
	#define TIMER2_CTC_VECTOR_ID	    4

void TIMER2_INIT(void);
void TIMER2_SET_PRELOAD(u8 Copy_u8Preload);
void TIMER2_SET_CTC(u8 Copy_u8CTC);
u8 TIMER2_GET_COUNTER_VALUE(void);	



u8 TIMER_u8SetCallBack(void (*Copy_pvCallBackFunc)(void) , u8 Copy_u8VectorID);

//Special functions for PWM
    void TIMER_SET_PWM(u16 Copy_u16CompareValue);
	u8   TIMER_GET_PWM_OnPeriod   (u16 * Copy_pu16OnPeriod);
	u8   TIMER_GET_PWM_TotalPeriod(u32 * Copy_pu32TotalPeriod);
	u8   TIMER_GET_PWM_DutyCycle  (u8  * Copy_pu8DutyCycle);
	
	
	
	
// ICU functions

    void TIMER_ICU_INIT_ENABLE();
	u8   TIMER_ICU_SET_TRIGGER_EDGE(u8 Copy_u8Edge);
	void TIMER_ICU_ENABLE_INTERRUPT();
	void TIMER_ICU_DISABLE_INTERRUPT();
	u16  TIMER_GET_ICR();


#endif
