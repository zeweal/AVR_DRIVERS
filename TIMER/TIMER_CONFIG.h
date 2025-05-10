/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    TIMER_CONFIG.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Abdallah Zeweal
 *  Layer  : MCAL
 *  SWC    : TIMER
 *
 */

 #ifndef TIMER_CONFIG_H_
 #define TIMER_CONFIG_H_

 //timer modes
#define TIMER_NORMAL_MODE       0
#define TIMER_CTC_MODE          1
#define TIMER_PWM_MODE          2
#define TIMER_FAST_PWM_MODE     3

//prescaller
 #define TIMER_NO_CLOCK_SOURCE                       0
 #define TIMER_NO_PRESCALLER_FACTOR                  1
 #define TIMER_FACTOR_8                              2
 #define TIMER_FACTOR_64                             4
 #define TIMER_FACTOR_256                            6
 #define TIMER_FACTOR_1024                           5
 #define TIMER_T0_EXTERNAL_CLOCK_SOURCE_FALLING      6
 #define TIMER_T0_EXTERNAL_CLOCK_SOURCE_RISING       7
 
 //////////////////////////////////////////////////////////  TIMER0 \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
 
 /*
 modes :-
     * 1. TIMER_NORMAL_MODE
	 * 2. TIMER_PWM_MODE
	 * 3. TIMER_CTC_MODE
	 * 4. TIMER_FAST_PWM_MODE
 */
 #define TIMER0_WAVEFORM_GENERATION_MODE TIMER_NORMAL_MODE
 
  /*
 prescaller :-
 1-TIMER_NO_CLOCK_SOURCE
 2-TIMER_NO_PRESCALLER_FACTOR
 3-TIMER_FACTOR_8
 4-TIMER_FACTOR_64
 5-TIMER_FACTOR_256
 6-TIMER_FACTOR_1024
 7-TIMER_T0_EXTERNAL_CLOCK_SOURCE_FALLING
 8-TIMER_T0_EXTERNAL_CLOCK_SOURCE_RISING
 
 */
 #define TIMER0_PRESCALLER TIMER_FACTOR_8
 
 
#if TIMER0_WAVEFORM_GENERATION_MODE == TIMER_NORMAL_MODE        //
 
    #define TIMER0_PRELOAD_VALUE   192
    #define TIMER0_OVERFLOW_INTERUPT ENABLE      
	
 
#elif TIMER0_WAVEFORM_GENERATION_MODE == TIMER_CTC_MODE            //
    #define TIMER0_CTC_VALUE   125
    /*Set Compare Match Output Mode
   		 * Choose between
   		 * 1. TIMER_OC_DISCONNECTED
   		 * 2. TIMER_OC_TOGGEL
   		 * 3. TIMER_OC_CLEAR
   		 * 4. TIMER_OC_SET
   		 */
    #define TIMER0_OC0_MODE   TIMER_OC_DISCONNECTED
    #define TIMER0_CTC_INTERRUPT			ENABLE

	
#elif TIMER0_WAVEFORM_GENERATION_MODE     TIMER_PWM_MODE         //

     #define TIMER0_CTC_VALUE						250
    /*Set PWM Mode
		 * Choose between
		 * 1. TIMER_OC_DISCONNECTED
		 * 2. TIMER_CLR_ON_CTC_SET_ON_TOP
		 * 3. TIMER_SET_ON_CTC_CLR_ON_TOP
		 */
    #define TIMER0_CTC_PWM_MODE TIMER_SET_ON_CTC_CLR_ON_TOP	
	
	
#elif TIMER0_WAVEFORM_GENERATION_MODE  TIMER_FAST_PWM_MODE      //
    
	#define TIMER0_CTC_VALUE						0
	/*Set PWM Mode
		 * Choose between
		 * 1. TIMER_OC_DISCONNECTED
		 * 2. TIMER_CLR_ON_CTC_SET_ON_TOP
		 * 3. TIMER_SET_ON_CTC_CLR_ON_TOP
		 */
    #define TIMER0_CTC_PWM_MODE 	TIMER_CLR_ON_CTC_SET_ON_TOP


#else 
	#error
#endif
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////TIMER2\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

 /*
 modes :-
     * 1. TIMER_NORMAL_MODE
	 * 2. TIMER_PWM_MODE
	 * 3. TIMER_CTC_MODE
	 * 4. TIMER_FAST_PWM_MODE
 */
 #define TIMER2_WAVEFORM_GENERATION_MODE     TIMER_CTC_MODE

  /*
 prescaller :-
 1-TIMER_NO_CLOCK_SOURCE
 2-TIMER_NO_PRESCALLER_FACTOR
 3-TIMER_FACTOR_8
 4-TIMER_FACTOR_64
 5-TIMER_FACTOR_256
 6-TIMER_FACTOR_1024
 7-TIMER_T0_EXTERNAL_CLOCK_SOURCE_FALLING
 8-TIMER_T0_EXTERNAL_CLOCK_SOURCE_RISING
 
 */
 #define TIMER2_PRESCALLER TIMER_FACTOR_64


#if TIMER2_WAVEFORM_GENERATION_MODE == TIMER_NORMAL_MODE
    #define TIMER2_PRELOAD_VALUE   192
    #define TIMER2_OVERFLOW_INTERUPT ENABLE

#elif TIMER2_WAVEFORM_GENERATION_MODE == TIMER_CTC_MODE
    #define TIMER2_CTC_VALUE   125
 
    /*Set Compare Match Output Mode
		 * Choose between
		 * 1. TIMER_OC_DISCONNECTED
		 * 2. TIMER_OC_TOGGEL
		 * 3. TIMER_OC_CLEAR
		 * 4. TIMER_OC_SET
		 */
    #define TIMER2_OC2_MODE TIMER_OC_DISCONNECTED
 
    #define TIMER2_CTC_INTERRUPT			ENABLE

	
	
#elif TIMER2_WAVEFORM_GENERATION_MODE     TIMER_PWM_MODE         //

     #define TIMER2_CTC_VALUE						250
    /*Set PWM Mode
		 * Choose between
		 * 1. TIMER_OC_DISCONNECTED
		 * 2. TIMER_CLR_ON_CTC_SET_ON_TOP
		 * 3. TIMER_SET_ON_CTC_CLR_ON_TOP
		 */
    #define TIMER2_CTC_PWM_MODE TIMER_SET_ON_CTC_CLR_ON_TOP	
	

#elif TIMER2_WAVEFORM_GENERATION_MODE  TIMER_FAST_PWM_MODE      //
    
	#define TIMER2_CTC_VALUE						0
	/*Set PWM Mode
		 * Choose between
		 * 1. TIMER_OC_DISCONNECTED
		 * 2. TIMER_CLR_ON_CTC_SET_ON_TOP
		 * 3. TIMER_SET_ON_CTC_CLR_ON_TOP
		 */
    #define TIMER2_CTC_PWM_MODE 	TIMER_CLR_ON_CTC_SET_ON_TOP
#endif
#endif

