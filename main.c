#define F_CPU 8000000UL
#define D4 eS_PORTC2
#define D5 eS_PORTC3
#define D6 eS_PORTC4
#define D7 eS_PORTC5
#define RS eS_PORTC0
#define EN eS_PORTC1

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "lcd.h"

unsigned int n = 0;
unsigned int s = 0;
unsigned int cnt = 0;
unsigned int j = 0;
unsigned int v = 0;
unsigned int pros = 0;
unsigned int p = 0;
unsigned char selj[]={'1','2','3','4'};
unsigned int vol[]={0,50,70,100,200};
unsigned int sjuice[4];
unsigned int vjuice[4];
unsigned int a;
unsigned int b;
unsigned char q;
unsigned char c[8];
unsigned char d[8];
unsigned int i=0;
unsigned int k=0;


void init(void);

int main(void){
	
	MCUCSR = 0x80;
	MCUCSR = 0x80;

	init();
	Lcd4_Init();
	sei();
	DDRC = 0xff;
	
	TCCR0A |=1<<COM0A0 |1<<COM0A1;
	TCCR1A |=1<<WGM11 | 1<<COM1A1| 1<<COM1A0 | 1<<COM1B0 | 1<<COM1B1;
	TCCR2A |=1<<COM2A0 | 1<<COM2A1; 
	TCCR1B |=1<<WGM12 | 1<<WGM13 | 1<<CS11 |1<<CS10;//8MHz/64 (From prescaler)
	ICR1 = 2499;//to get 50 Hz or 20 ms

	
	
	//PB1(OC1A),PB2(OC1B),PB3(OC2A),PD6(OC0A) represent juice1, juice2, juice3, juice4 respectively for the servo motors. 
	if(p==1){
		for(i=0;i<4;i++){
			if(sjuice[i]==1){//PB1
				if(vjuice[i]==0){
				//nothing to do
				}else if(vjuice[i]==50){
						OCR1A = ICR1-105;
						_delay_ms(1000);
						OCR1A = ICR1-318;
						_delay_ms(1000);
				}else if(vjuice[i]==70){
						OCR1A = ICR1-105;
						_delay_ms(1000);
						OCR1A = ICR1-318;
						_delay_ms(1000);
						OCR1A = ICR1-233;
						_delay_ms(1000);
						OCR1A = ICR1-318;
						_delay_ms(1000);
				}else if(vjuice[i]==100){
					for(k=0;k<2;k++){
						OCR1A = ICR1-105;
						_delay_ms(1000);
						OCR1A = ICR1-318;
						_delay_ms(1000);
					}
				}else if(vjuice[i]==200){
					for(k=0;k<4;k++){
						OCR1A = ICR1-105;
						_delay_ms(1000);
						OCR1A = ICR1-318;
						_delay_ms(1000);
					}
				}else{
				}
			}else if(sjuice[i]==2){//PB2
				if(vjuice[i]==0){
				//nothing to do
				}else if(vjuice[i]==50){
						OCR1B = ICR1-105;
						_delay_ms(1000);
						OCR1B = ICR1-318;
						_delay_ms(1000);
				}else if(vjuice[i]==70){
						OCR1B = ICR1-105;
						_delay_ms(1000);
						OCR1B = ICR1-318;
						_delay_ms(1000);
						OCR1B = ICR1-233;
						_delay_ms(1000);
						OCR1B = ICR1-318;
						_delay_ms(1000);
				}else if(vjuice[i]==100){
					for(k=0;k<2;k++){
						OCR1B = ICR1-105;
						_delay_ms(1000);
						OCR1B = ICR1-318;
						_delay_ms(1000);
					}
				}else if(vjuice[i]==200){
					for(k=0;k<4;k++){
						OCR1B = ICR1-105;
						_delay_ms(1000);
						OCR1B = ICR1-318;
						_delay_ms(1000);
					}
				}else{
				}
			}else if(sjuice[i]==3){//PB3
				if(vjuice[i]==0){
				//nothing to do
				}else if(vjuice[i]==50){
						OCR2A = ICR1-105;
						_delay_ms(1000);
						OCR2A = ICR1-318;
						_delay_ms(1000);
				}else if(vjuice[i]==70){
						OCR2A = ICR1-105;
						_delay_ms(1000);
						OCR2A = ICR1-318;
						_delay_ms(1000);
						OCR2A = ICR1-233;
						_delay_ms(1000);
						OCR2A = ICR1-318;
						_delay_ms(1000);
				}else if(vjuice[i]==100){
					for(k=0;k<2;k++){
						OCR2A = ICR1-105;
						_delay_ms(1000);
						OCR2A = ICR1-318;
						_delay_ms(1000);
					}
				}else if(vjuice[i]==200){
					for(k=0;k<4;k++){
						OCR2A = ICR1-105;
						_delay_ms(1000);
						OCR2A = ICR1-318;
						_delay_ms(1000);
					}
				}else{
				}
			}else{		//PD6
				if(vjuice[i]==0){
				//nothing to do
				}else if(vjuice[i]==50){
						OCR0A = ICR1-105;
						_delay_ms(1000);
						OCR0A = ICR1-318;
						_delay_ms(1000);
				}else if(vjuice[i]==70){
						OCR0A = ICR1-105;
						_delay_ms(1000);
						OCR0A = ICR1-318;
						_delay_ms(1000);
						OCR0A = ICR1-233;
						_delay_ms(1000);
						OCR0A = ICR1-318;
						_delay_ms(1000);
				}else if(vjuice[i]==100){
					for(k=0;k<2;k++){
						OCR0A = ICR1-105;
						_delay_ms(1000);
						OCR0A = ICR1-318;
						_delay_ms(1000);
					}
				}else if(vjuice[i]==200){
					for(k=0;k<4;k++){
						OCR0A = ICR1-105;
						_delay_ms(1000);
						OCR0A = ICR1-318;
						_delay_ms(1000);
					}
				}else{
				}
			}

		}

	Lcd4_Init();
	Lcd4_Clear();
	Lcd4_Set_Cursor(1,0);
    	Lcd4_Write_String("  YOUR DRINK IS ");
	Lcd4_Set_Cursor(2,0);
    	Lcd4_Write_String("     READY!     ");
	_delay_ms(5000);

	p=0;
	j=0;
	v=0;
	s=0;
	n=0;
	cnt=0;
	pros=0;
	
	}
while(1){
Lcd4_Init();
Lcd4_Clear();
Lcd4_Set_Cursor(1,0);
Lcd4_Write_String("  Juice Mixer ");
Lcd4_Set_Cursor(2,0);
Lcd4_Write_String("Select Menu");
_delay_ms(5000);
}
	
return 0;
}

void init(void){
	//PB1(OC1A),PB2(OC1B),PB3(OC2A),PD6(OC0A) represent juice1, juice2, juice3, juice4 respectively for the servo motors. 
	//PD2(INT0), PD3(INT1), PD1 are used to get encoder inputs
	//PC0-RS, PC1-E,PC2,PC3,PC4,PC5 are used to interface lcd in 4 bit mode
	DDRC =0xff;
	DDRD = 0xff;
	DDRB = 0x0e;  // PB3(OC2A) and PB0 as output
 	//PORTB |= ;
	DDRD &= ~(1<<PD2)|~(1<<PD1);//Makes pd1,2 pin of PORTD as Input
	

	//set the timer for prescaling of 64
	//TCCR0|= 1<<FOC0 | 1<<WGM01 | 1<<CS01 | 1<<CS00;

	GICR |=1<<INT1 | 1<< INT0; //	enable external interrupts
	MCUCR = 1<<ISC01 | 1<<ISC00 | 1<<ISC11 | 1<<ISC10;
	TIMSK |=1<<OCIE0;
}

ISR(INT0_vect){

if(pros!=1){

	if(n==0){
		
		if(PIND & (1<<PD1)){
		q=selj[j];

		Lcd4_Init();
		Lcd4_Clear();
		Lcd4_Set_Cursor(1,0);
    		Lcd4_Write_String("Juice");
		Lcd4_Set_Cursor(1,7);
    		Lcd4_Write_String(q);
		Lcd4_Set_Cursor(2,0);
		Lcd4_Write_String("     Select     ");
		j++;
		if(j>=4){j=0;}
		}else{
		q=selj[j];

		Lcd4_Init();
		Lcd4_Clear();
		Lcd4_Set_Cursor(1,0);
    		Lcd4_Write_String("Juice");
		Lcd4_Set_Cursor(1,7);
    		Lcd4_Write_String(q);
		Lcd4_Set_Cursor(2,0);
		Lcd4_Write_String("     Select     ");
		j--;
		if(j<0){j=3;}
		}

	}else{
		
		if(PIND & (1<<PD1)){
		a=vol[v];
		itoa(a,c,10);
		Lcd4_Init();
		Lcd4_Clear();
		Lcd4_Set_Cursor(1,0);
    		Lcd4_Write_String(c);
		Lcd4_Set_Cursor(1,5);
    		Lcd4_Write_String("ml");
		Lcd4_Set_Cursor(2,0);
		Lcd4_Write_String("     Select     ");
		v++;
		if(v>=5){v=0;}
		}else{
		a=vol[v];
		itoa(a,c,10);
		Lcd4_Init();
		Lcd4_Clear();
		Lcd4_Set_Cursor(1,0);
    		Lcd4_Write_char(c);
		Lcd4_Set_Cursor(1,5);
    		Lcd4_Write_String("ml");
		Lcd4_Set_Cursor(2,0);
		Lcd4_Write_String("     Select     ");
		v--;
		if(v<0){v=4;}
		}	

	}

}else{

if(p!=1){

if(PIND & (1<<PD1)){
b=vjuice[s];
itoa(b,d,10);
q=selj[j];

Lcd4_Init();
Lcd4_Clear();
Lcd4_Set_Cursor(1,0);
Lcd4_Write_String("Juice");
Lcd4_Set_Cursor(1,6);
Lcd4_Write_String(q);
Lcd4_Set_Cursor(1,8);
Lcd4_Write_char(d);
Lcd4_Set_Cursor(2,0);
Lcd4_Write_String("     Start      ");
s++;
if(s>=4){s=0;}
}else{
b=vjuice[s];
itoa(b,d,10);
q=selj[j];

Lcd4_Init();
Lcd4_Clear();
Lcd4_Set_Cursor(1,0);
Lcd4_Write_String("Juice");
Lcd4_Set_Cursor(1,6);
Lcd4_Write_String(q);
Lcd4_Set_Cursor(1,8);
Lcd4_Write_String(d);
Lcd4_Set_Cursor(2,0);
Lcd4_Write_String("     Start     ");
s--;
if(s<0){s=3;}
}
}
	
}

}

ISR(INT1_vect){
n++;
if(n>=2){n=0;}
if((cnt%2==0)&&(cnt<=7)){
sjuice[j]=j+1;
}else{
vjuice[j]=vol[v];
j=0;
v=0;
}

cnt++;
if(cnt==8){
pros=1;
n=0;
}

if(cnt==9){
p=1;
n=0;
}




}






















