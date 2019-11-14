#include <p18f4550.h>
#include "delays.h"
#include "lcd.h"
#include "senha.h"
#include "eeprom.h"
#include "menu.h"
#include "MCC18_18F4550.h"

void main (void){
   
   /* 
   char a;
   char vet[6];
   int result = 1;
   Inicializa_LCD();
   //reiniciarPadrao();
   */
   while(1){
    //reiniciarPadrao();
    //reiniciarConfiguracaoInicial();//reinicia para senha root 123456(1ºacesso)
     iniciar();  
    // implementar parte do segundo acesso
    
    /*
    PORTCbits.RC0 = 1;
    
    Delay10KTCYx(50);
    
    pedeSenha(vet);
      
    Delay10KTCYx (15);

    verificaSenha(vet);
     * */
   }
}

 /*
void Inic_Regs(void)
{
	TRISA = 0x00;			//configura PORTA   1 para entrada e 0 para saida
	TRISB = 0x00;			//configura PORTB
	TRISC = 0x00;			//configura PORTC
	TRISD = 0x00;			//configura PORTD
	TRISE = 0x00;			//configura PORTE
	ADCON1 = 0x0F;			//configura pinos como digitais
	PORTA = 0x00;			//inicializa PORTA  como as portas irão iniciar? se for em nivel baixo 0 em alto 1
	PORTB = 0x00;			//inicializa PORTB
	PORTC = 0x00;			//inicializa PORTC
	PORTD = 0x00;			//inicializa PORTD
	PORTE = 0x00;			//inicializa PORTE
//********************************************************************
}*/
 
 