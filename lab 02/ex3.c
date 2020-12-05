#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 100

int main(){
 
	DDRD = DDRD & ~(1<<2);	//PD2 (INT0) is input 

	DDRB = DDRB |0x3F;	//PB 0 to 5  are the output
  
	EICRA |= (1<<ISC01); //Set for falling rdge detecting
	EICRA |= (0<<ISC00); //set for falling edge detecting	

	sei(); //enable the globale interrupt

	EIMSK |= (1<<INT0); //enable the external ineterrupts
	while(1){
	
	}
	return 0;
}

unsigned char count=0;
ISR(INT0_vect){
  	//invert the count
  	count=(count+1);
  	//setting the count value int portB 
	PORTB =(PORTB & 0 )|count ;  
   
}