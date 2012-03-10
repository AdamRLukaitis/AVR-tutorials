/*

This sketch can create frequencies easily up to ~40kHz and any duty
cycle you want. 
Every single channel of the software PWM can be set to 
a different duty cycle.
 
*/

#define F_CPU 16000000UL
#define F_PWM 10000 // PWM frequency 
#define Prescaler 8
#define ICR1_val ((F_CPU / F_PWM) / Prescaler) - 1

#define PWM_DDR DDRD
#define PWM_PORT PORTD

uint16_t PWM_setting[8];
uint8_t tmp;

void setup(){

  TCCR1B |= (1<<WGM13) | (1<<WGM12) | (1<<CS11); // CTC Mode prescaler 8
  
  ICR1 = ICR1_val;
  
  PWM_DDR |= 0xFF;
  
  for(uint8_t i = 0; i < 8; i++){
    PWM_setting[i] = (((F_CPU / F_PWM) / Prescaler) - 1) / 2; // 50% duty cycle
  }
}

void loop(){
  
  tmp = 0; 
			
  if(PWM_setting[0] > TCNT1) tmp |= (1<<0);
  if(PWM_setting[1] > TCNT1) tmp |= (1<<1);
  if(PWM_setting[2] > TCNT1) tmp |= (1<<2);
  if(PWM_setting[3] > TCNT1) tmp |= (1<<3);
  if(PWM_setting[4] > TCNT1) tmp |= (1<<4);
  if(PWM_setting[5] > TCNT1) tmp |= (1<<5);
  if(PWM_setting[6] > TCNT1) tmp |= (1<<6);
  if(PWM_setting[7] > TCNT1) tmp |= (1<<7);
		
  PWM_PORT = tmp;
  
}
