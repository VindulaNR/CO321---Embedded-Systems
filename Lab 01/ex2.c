#include <avr/io.h>

int main()
{
	DDRD  |=0b00000001;//out put  	
    DDRC &=~(1<<1);//input
  
  
    ADMUX  |= (1<<MUX0);     // Select A1 from the MUX, MUX=001
    ADMUX  |=(1<<ADLAR); //select left adugested
   	ADCSRA |= (1<<ADEN);  //enable the ADC
    ADCSRA |=  0b00000111;  //select 128 scaller
      
     ADMUX |= 0b00000000; //select ref as VRef
  
    while(1){
  		ADCSRA |= (1<<ADSC); //start the convention
  
   while(((ADCSRA>>ADIF) & 1)==0){}   // Wait until ADC conversion ends
      
      if(ADCH<100){  //led on
        PORTD |= 0b00000001; 
      }
      else {
      	 PORTD &=~ 0b00000001; //led off
      }
     		
      	_delay_ms(100);
    }	
	return 0;
}