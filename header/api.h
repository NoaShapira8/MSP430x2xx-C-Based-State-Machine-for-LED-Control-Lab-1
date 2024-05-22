#ifndef _api_H_
#define _api_H_

#include  "../header/halGPIO.h"     // private library - HAL layer


//extern void printSWs2LEDs(void);
extern void printArr2LEDs(char Arr[],int size);
extern void MakePWM(void) ; 
void incLEDs(char,int* state4Rotate);
extern void func4(int Duty, int Nfreq, char ch) ; 
extern void pwm(int Duty,int Nfreq ) ; 

#endif







