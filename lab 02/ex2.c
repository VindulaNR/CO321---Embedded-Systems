//togling the led in falling edge using interrupt
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 100

int main(){
 
  DDRD = DDRD & ~(1<<2);  //PD2 (INT0) is input 

  DDRB = DDRB |(1<<0);  //PB0 is the output
  
  EICRA |= (1<<ISC01); //Set for falling rdge detecting
  EICRA |= (0<<ISC00); //set for falling edge detecting 

  sei(); //enable the globale interrupt

  EIMSK |= (1<<INT0); //enable the external ineterrupts INT0
  while(1){
  
  }
  return 0;
}

unsigned char count=0;
ISR(INT0_vect){
    //invert the count
    count=(!count);
    //if count is 1 give the 1 to 0th bit
    if (count){
    PORTB = PORTB |(1<<0) ;  
    }
    //if count is 0 give the 0 to 0th bit
    else{
        PORTB = PORTB & (0<<0);
    }

}