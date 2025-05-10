/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    TIMER_PRIVATE.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Abdallah Zeweal
 *  Layer  : MCAL
 *  SWC    : TIMER
 *
 */
 #ifndef TIMER_PRIVATE_H_
 #define TIMER_PRIVATE_H_
 
  #define TIMSK *((volatile u8*)0x59)
// bits of TIMSK/////////////////////////////////////////////
#define TIMSK_TOIE0 0 //Compare Match interrupt is enabled
#define TIMSK_OCIE0 1 // Overflow interrupt is enabled
#define TIMSK_TOIE1 2 
#define TIMSK_OCIE1B 3
#define TIMSK_OCIE1A 4
#define TIMSK_TICIE1 5

//////////////////////////////////////////////////////////////
  #define TIFR  *((volatile u8*)0x58)
  // its bits ////////////////////////////////////////////////
  #define TIFR_TOV0 0
  #define TIFR_OCF0 1
  #define TIFR_TOV1 2
  #define TIFR_OCF1B 3
  #define TIFR_OCF1A 4
  #define TIFR_ICF1 5
  #define TIFR_TOV2 6
  #define TIFR_OCF2 7
  ///////////////////////////////////////////////////////////////
  #define SFIOR *((volatile u8*)0x50)
  #define SFIOR_PSR10 0  //the prescaller bit in SFIOR When this bit is written to one, the Timer/Counter1 and Timer/Counter0 prescaler will be reset
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // TIMER0
 #define TCNT0 *((volatile u8*)0x52)
 #define TCCR0 *((volatile u8*)0x53)
//bits of TCCR0 /////////////////////////////////////////////////////////////////////////////////////////////////////
 #define TCCR0_CS00      0    //The three Clock Select bits select the clock source to be used by the Timer/Counter
 #define TCCR0_CS01      1    //The three Clock Select bits select the clock source to be used by the Timer/Counter
 #define TCCR0_CS02      2    //The three Clock Select bits select the clock source to be used by the Timer/Counter
 #define TCCR0_WGM01     3   // set the timer mode 
 #define TCCR0_COM00     4   //These bits control the Output Compare pin (OC0) behavior depending on WGM00 , WGM01
 #define TCCR0_COM01     5   //These bits control the Output Compare pin (OC0) behavior depending on WGM00 , WGM01
 #define TCCR0_WGM00     6  //set the timer mode 
 #define TCCR0_FOC0      7  // always 1 to ensure non PMW mode 
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 #define OCR0  *((volatile u8*)0X5C)
 #define DISABLE 0
 #define ENABLE  1
 #define TIMER_PRESCALER_MASK 0b11111000
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//TIMER1
#define TCCR1A *((volatile u8*)0x4F)
//its bits 
#define COM1A1 7 // Compare the output mode for channel A
#define COM1A0 6 // Compare the output mode for channel A
#define COM1B1 5 // Compare the output mode for channel B
#define COM1B0 4 // Compare the output mode for channel B
#define FOC1A 3 //Force Output Compare for Channel A
#define FOC1B 2 //Force Output Compare for Channel B
#define WGM11 1 //Waveform Generation Mode
#define WGM10 0 //Waveform Generation Mode
 
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//TIMER2
#define TCCR2 *((volatile u8*)0x45)
//it bits
#define TCCR2_FOC2 7 //Force Output Compare
#define TCCR2_WGM20 6 // Waveform generation mode
#define TCCR2_COM21 5 // Compare match Output mode
#define TCCR2_COM20 4 // Compare match Output mode
#define TCCR2_WGM21 3 // Waveform Generation Mode
#define TCCR2_CS22 2 // Clock Select 
#define TCCR2_CS21 1 // Clock Select
#define TCCR2_CS20 0 // Clock Select 

#define TCNT2 *((volatile u8*)0x44)
#define OCR2 *((volatile u8*)0x43)
#define ASSR *((volatile u8*)0x42)
//its bits
#define AS2 3 // Asynchronous Timer/Counter2
#define TCN2UB 2 // Timer/Counter2 Update Busy
#define OCR2UB 1 //Output Compare Register2 Update Busy
#define TCR2UB 0 // Timer/Counter Control Register2 Update Busy

// TIMSK bits
#define TIMSK_TOIE2 6 // Timer/Counter2 Overflow Interrupt Enable
#define TIMSK_OCIE2 7 //Timer/Counter2 Output Compare Match Interrupt Enable

//TIFR bits 
#define TIFR_TOV2 6 // Timer/Counter2 Overflow Flag
#define TIFR_OCF2 7 // Output Compare Flag 2

//SFIOR bits
#define SFIOR_PSR2 1 //: Prescaler Reset Timer/Counter2




	#define FALLING_EDGE				                    0
	#define RISING_EDGE					                    1
	

	#define TIMER_OC_DISCONNECTED					        0
	#define TIMER_OC_TOGGEL							        1
	#define TIMER_OC_LOW							        2
	#define TIMER_OC_HIGH							        3

	#define TIMER_OC_DISCONNECTED					        0
	#define TIMER_CLR_ON_CTC_SET_ON_TOP				        2
	#define TIMER_SET_ON_CTC_CLR_ON_TOP				        3








 #endif


  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

