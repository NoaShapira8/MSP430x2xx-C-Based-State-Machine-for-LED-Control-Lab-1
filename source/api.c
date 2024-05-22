#include  "../header/api.h"    		// private library - API layer
#include  "../header/halGPIO.h"     // private library - HAL layer

//-------------------------------------------------------------
//            Print SWs value onto LEDs
//-------------------------------------------------------------
/*
void printSWs2LEDs(void){
	unsigned char ch;
	
	ch = readSWs();
	print2LEDs(ch);
}
*/

//---------------------------------------------------------------------
//             Mul/Div LEDs shown value 
//---------------------------------------------------------------------
void incLEDs(char cycles,int* Val2Rotate){
  int i ; 
  for (i=0; i<cycles ;i++) {
          print2LEDs(*Val2Rotate) ; 
          *Val2Rotate=(*Val2Rotate*2)%255 ; 
          delay(LEDs_SHOW_RATE);	// delay of 500 [ms]
        }
}
        
//--------------------------------------------------------------------
//            Print array to LEDs array with rate of LEDs_SHOW_RATE
//--------------------------------------------------------------------            

void printArr2LEDs(char Arr[],int size ){
	unsigned int i ;
	for(i=0; i<size; i++){
		print2LEDs(Arr[i]-'0');
		delay(LEDs_SHOW_RATE);
	}
}

//--------------------------------------------------------------------
//            Makes PWM with Duty Cycle of 75%
//--------------------------------------------------------------------            
void MakePWM(void) {
  PortIsOne(); 
  delay(OneTime) ; 
  PortIsZero() ; 
  delay(ZeroTime) ; 
}

void func4(int Duty, int Nfreq, char ch) {
  ch=readSWs(ch) ; 
  if(ch==0x10) {
    Duty= 0 ; 
    pwm(Duty,Nfreq) ; 
  }
  else if (ch==0x20) {
    Duty =0x0D ; 
    pwm (Duty,Nfreq) ; 
  }
  else if ( ch== 0x30) { 
    Duty = 0x20 ; 
    pwm (Duty,Nfreq) ; 
  }
  else {
    Duty = 0x34 ; 
    pwm (Duty,Nfreq) ; 
  } 
}

void pwm(int Duty,int Nfreq ) {
  if (Duty ==0) {
    PortIsZero() ; 
  }
  else if (Duty == 0x34 ) {
    PortIsOne() ; 
  }
  
  else {
    PortIsOne(); 
    delay(Duty) ; 
    PortIsZero(); 
    delay(Nfreq-Duty) ;
  }
}






