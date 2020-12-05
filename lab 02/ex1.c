//Display the how many tymes push button is pressedd

#include <avr/io.h>


int main(){
  DDRD = DDRD & ~(1<<7);  //setting the 7 bit of the porftD as input
  DDRB = DDRB | 0x3F;   //setting first 6 bit of the port b as output
    
    unsigned char count=0;    
    unsigned char current_state=0;
    unsigned char previouse_state=0;
    unsigned char is_pushbutton_just_pressed=0;
  
    //while loop to do the proccess continousely
  while(1){
        //check the current state of the pushbutton
        current_state=((PIND & (1<<7))==(1<<7));
        //check the pushbutton is just prssed and take it as possitive edge
        is_pushbutton_just_pressed=(current_state && !previouse_state);
        //set the previose state as current state
        previouse_state= current_state;
      
    //check is the button pressed just now (possitive edge)     
    if(is_pushbutton_just_pressed){
            //increment the count
            count=count+1;
            //give value of count to the bit of portb
      PORTB =(PORTB & 0 )|count;
          
            //PORTB =(PORTB & count)|(~PORTB & count);
        }
      
  }
  return 0;
}