#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>

#define F_PWM 10000
#define Prescaler 8
#define ICR1_val ((F_CPU / F_PWM) / Prescaler) - 1

uint16_t PWM_setting[8];

int main(void){
	
	TCCR1B = (1<<WGM13) | (1<<WGM12) | (1<<CS11); // CTC mode prescaler 8
	
	ICR1 = ICR1_val;
	
	DDRD = 0xFF;
	
	uint8_t tmp;
	
	for(uint8_t i = 0; i < 8; i++){
		PWM_setting[i] = (((F_CPU / F_PWM) / Prescaler) - 1) / 2; // set duty cycle
	}

	while(1){
		
		tmp = 0; 
			
		if(PWM_setting[0] > TCNT1) tmp |= (1<<0);
		if(PWM_setting[1] > TCNT1) tmp |= (1<<1);
		if(PWM_setting[2] > TCNT1) tmp |= (1<<2);
		if(PWM_setting[3] > TCNT1) tmp |= (1<<3);
		if(PWM_setting[4] > TCNT1) tmp |= (1<<4);
		if(PWM_setting[5] > TCNT1) tmp |= (1<<5);
		if(PWM_setting[6] > TCNT1) tmp |= (1<<6);
		if(PWM_setting[7] > TCNT1) tmp |= (1<<7);
		
		PORTD = tmp;
	}
	
	return 0;
}

