#include  "../header/bsp.h"    // private library - BSP layer

//-----------------------------------------------------------------------------  
//           GPIO congiguration
//-----------------------------------------------------------------------------
void GPIOconfig(void){
 // volatile unsigned int i; // in case of while loop usage
  
  WDTCTL = WDTHOLD | WDTPW;		// Stop WDT
   
  // LEDs 8-bit Array Port configuration
  LEDsArrPortSel &= ~0xFF;            // GPIO capability , makes them zeroes.
  LEDsArrPortDir |= 0xFF;             // output dir , makes them one ( output )
  LEDsArrPort = 0x00;		      // clear all LEDs
  
  /* Switches Setup
  SWsArrPortSel &= ~0x0F;
  SWsArrPortDir &= ~0x0F;
  */
  
  // PushButtons Setup
  PBsArrPortSel &= ~0x0F;           // make P2.0-P2.3 IO mode
  PBsArrPortSel &= ~0x80 ;          // make P2.7 IO mode
  PBsArrPortDir &= ~0x0F;           // make P2.0-P2.3 in mode
  PBsArrPortDir |= 0x80 ;           // make P2.7 out mode
  PBsArrIntEdgeSel |= 0x03;  	     // pull-up mode  . when pushing the voltage decrease.
  PBsArrIntEdgeSel &= ~0x0C;         // pull-down mode . when pushing the voltage increase.
  PBsArrIntEn |= 0x0F;               // Remember to make the 4th PB's interrups enabled 
  PBsArrIntPend &= ~0x0F;            // clear pending interrupts 
  
  _BIS_SR(GIE);                     // enable interrupts globally
  
  
}                             
//------------------------------------------------------------------------------------- 
//            Timers congiguration 
//-------------------------------------------------------------------------------------
void TIMERconfig(void){
	
	//write here timers congiguration code
} 
//------------------------------------------------------------------------------------- 
//            ADC congiguration 
//-------------------------------------------------------------------------------------
void ADCconfig(void){
	
	//write here ADC congiguration code
}              

           
             

 
             
             
            
  

