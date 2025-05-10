/*
//////////////////////////////////////////////////////////////////////////BUZ_PROGRAM.h\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
Auothor: Abdallah Zeweal
Layer: HAL
SWC: BUZ
*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_INTERFACE.h"
#include "BUZ_INTERFACE.h"
#include "BUZ_CONFIG.h"
#include "BUZ_PRIVATE.h"



/*
* Berief:
      =>this function is used to initialize the buzzer as output
* Parameters :
  	   => struct has the buzzer porn , pin , status
*/

void BUZ_INIT(BUZ_TYPE BUZ_CONFIG){
     DIO_SET_PIN_DIRECTION( BUZ_CONFIG.PORT, BUZ_CONFIG.PIN , DIO_PIN_OUTPUT );	
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
* Berief:
      =>this function is used to make the buzzer on 
* Parameters :
  	   => struct has the buzzer porn , pin , status
*/
void BUZ_ON(BUZ_TYPE BUZ_CONFIG){
	 if(BUZ_CONFIG.ACTIVATE_STATE==ACTIVE_HIGH){
		 DIO_SET_PIN_VALUE( BUZ_CONFIG.PORT, BUZ_CONFIG.PIN , DIO_PIN_HIGH);
	 }
	 else if (BUZ_CONFIG.ACTIVATE_STATE==ACTIVE_LOW){
		 DIO_SET_PIN_VALUE( BUZ_CONFIG.PORT, BUZ_CONFIG.PIN , DIO_PIN_LOW);
	 }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
* Berief:
      =>this function is used to make the buzzer off
* Parameters :
  	   => struct has the buzzer porn , pin , status
*/
void BUZ_OFF(BUZ_TYPE BUZ_CONFIG){
	 if(BUZ_CONFIG.ACTIVATE_STATE==ACTIVE_HIGH){
		 DIO_SET_PIN_VALUE( BUZ_CONFIG.PORT, BUZ_CONFIG.PIN , DIO_PIN_LOW);
	 }
	 else if (BUZ_CONFIG.ACTIVATE_STATE==ACTIVE_LOW){
		 DIO_SET_PIN_VALUE( BUZ_CONFIG.PORT, BUZ_CONFIG.PIN , DIO_PIN_HIGH);
	 }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
* Berief:
      =>this function is used to toggle the buzzer
* Parameters :
  	   => struct has the buzzer porn , pin , status
*/
void BUZ_TOGGLE(BUZ_TYPE BUZ_CONFIG){
	DIO_TOGGLE_PIN_VALUE( BUZ_CONFIG.PORT , BUZ_CONFIG.PIN);
}
