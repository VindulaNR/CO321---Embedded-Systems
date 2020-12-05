//Display the 6 recent pushbutton squenz

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 100

int main(){
 
	DDRD = DDRD & ~((1<<2)|(1<<3));	//PD2 (INT0) PD2(IN1) are input 

	DDRB = DDRB |0x3F;	//PB 0 to 5  are the output
  
	EICRA |= (1<<ISC01); //Set for rising rdge detecting
	EICRA |= (1<<ISC00); //set for rising edge detecting
  	EICRA |= (1<<ISC11); //set for rising edge detecting	
	EICRA |= (1<<ISC10); //set for rising edge detecting	

	sei(); //enable the globale interrupt

	EIMSK |= ((1<<INT0)|(1<<INT1)); //enable the external ineterrupts for INT0 and INT1
 
	while(1){
	
	}
	return 0;
}
unsigned char count=0;
ISR(INT0_vect){
  	//when Push button according to 1 is pressed
  	//by incrementing the count by 1 give the 1 to the 0 th bit
  	count=count+1;
  	//setting the count value int portB 
	PORTB =(PORTB & 0 )|count ;
  	//by adding the same value the binary representation will shift to left by 1bit
  	//and 0th bit will be 0
  	count=count+count;
   
}
ISR(INT1_vect){
  	//No need of setting when 0 is pressed 
  	//initialy 0th bit is 0
  	//setting the count value int portB 
	PORTB =(PORTB & 0 )|count ;
  	//by adding the same value the binary representation will shift to left by 1bit
  	//and 0th bit will be 0
  	count=count+count;   
}