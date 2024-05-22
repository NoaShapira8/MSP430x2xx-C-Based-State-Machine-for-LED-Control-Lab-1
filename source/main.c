#include  "../header/api.h"    		// private library - API layer
#include  "../header/app.h"    		// private library - APP layer

enum FSMstate state;
enum SYSmode lpm_mode;

void main(void){
  
  state = state0;  // start in idle state on RESET
  lpm_mode = mode0;     // start in idle state on RESET
  sysConfig();
  char ID[]={'3','1','8','3','5','7','6','5','4'} ; 
  int IDsize = 9 ; 
  int InitRotateVal=1 ; 
  int *Val2Rotate = &InitRotateVal ; 
  int Duty,Nfreq=0x34 ; 
  char ch ; 
  
  while(1){
	switch(state){
          
        case state0:
                clrLEDs() ; 
                enterLPM(lpm_mode);
		break;
          
	  case state1:
                disable_interrupts() ; 
		printArr2LEDs(ID,IDsize) ; 
                enable_interrupts() ; 
                clrLEDs() ; 
                enterLPM(lpm_mode);
		break;
		 
	  case state2:
		disable_interrupts();
		incLEDs(14,Val2Rotate) ; 
		enable_interrupts();
                clrLEDs() ; 
                enterLPM(lpm_mode);
		break;
		 
	  case state3:
		clrLEDs() ; 
                MakePWM() ; 
		break;
                
          case state4 : 
          clrLEDs() ; 
          func4 (Duty, Nfreq,ch) ; 
          break ; 
		
	}
  }
}
  
  
  
  
  
  