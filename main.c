#include<avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <util/atomic.h>


int main(void){
    DDRD =  0b11111111;
    PORTD = 0b11111111;

    cli();
    

   
    //Timer init
    // WGM == 001 - output compare
    TCCR2A |= (1<<WGM20); 
    // COM2B == 10 - Clear OC2B on compare match
    TCCR2A |= (1<<COM2B1); 

    // CS == 001 
    TCCR2B = 0b00000001;

    
    OCR2B =155; // set pwm duty
    sei();
    
    return 0;
}