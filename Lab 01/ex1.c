#include <avr/io.h>

int main()
{
	DDRD  =0xff;//out put
    DDRC &=~(1<<1);//input
  
  
    ADMUX  |= (1<<MUX0);     // Select A1 from the MUX, MUX=001
    ADMUX  |=(1<<ADLAR); //left adugested
   	ADCSRA |= (1<<ADEN);  //enable the ADC
    ADCSRA |=  0b00000111;  //select 128 scaller
      
     ADMUX |= 0b01000000; //select ref as avcc
  
    while(1){
  		ADCSRA |= (1<<ADSC); //start the convention
  
      
   while(((ADCSRA>>ADIF) & 1)==0){}   // Wait until ADC conversion ends
          
      if(ADCH>224){
        PORTD =0b11111111;}   //port out
      
      else if(ADCH>196){
        PORTD=0b01111111; }  //port out
      
      else if(ADCH>168){
        PORTD=0b00111111; }//port out
       
      else if(ADCH>140){
        PORTD=0b00011111; }  //port out
      
      else if(ADCH>112){
        PORTD=0b00001111; } //port out
      
      else if(ADCH>84){
        PORTD=0b00000111; } //port out
      
      else if(ADCH>56){
        PORTD=0b00000011; }  //port out
      
      else if(ADCH>28){
        PORTD=0b00000001; }  //port out
      
       else if(ADCH<28){
        PORTD=0b00000000; }  //port out
    
      		_delay_ms(100);
    }	
	return 0;
}