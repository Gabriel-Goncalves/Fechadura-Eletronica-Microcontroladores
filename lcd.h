#ifndef LCD_H_
#define LCD_H_

// ================================================================= //
// BIBLIOTECA PARA CONTROLE DE DISPLAY LCD 2x16 e 4x16               //
//                                                                   //
// ESCOLA SENAI A. JACOB LAFER - CURSO TÉCNICO DE ELETROELETRÔNICA   //
// DATA: 19/02/2016 - REVISÃO: A                                     //
// ================================================================= //
#include <delays.h>

// ================================================================= //
// DEFINIÇÕES DE HARDWARE                                            //
// ================================================================= //
#define RS_LCD PORTEbits.RE0
#define RW_LCD PORTEbits.RE2
#define EN_LCD PORTEbits.RE1
#define DATA_LCD PORTD

/*
#pragma config FOSC = HS
#pragma config PWRT = ON
#pragma config PBADEN = OFF
#pragma config WDT = OFF
#pragma config LVP = OFF
*/
// ================================================================= //
// SUB-ROTINA DE CONTROLE DE LCD                                     //
// ================================================================= //
void Comando_LCD (unsigned char comando){
   RS_LCD = 0;
   RW_LCD = 0;
 
   DATA_LCD = comando;
   EN_LCD = 1;
   Delay10TCYx (20);
   EN_LCD = 0;
   Delay1KTCYx (10);
}

// ================================================================ //
// SUB-ROTINA DE POSICIONAMENTO DE ESCRITA DE LCD                   //
// ================================================================ //
void Posiciona_LCD (unsigned char linha, unsigned char coluna){
   unsigned char x = 0;
   --coluna;

   switch (linha){
      case 1:  x = 0x80 + coluna;
               break;
 
      case 2:  x = 0xC0 + coluna;
               break;
 
      case 3:  x = 0x90 + coluna;
               break;
 
      case 4:  x = 0xD0 + coluna;
               break;

      default: break;
   }

   if (x != 0) Comando_LCD (x); 
} 

// ================================================================ //
// SUB-ROTINA DE ESCRITA DE CARACTER NO LCD                         //
// ================================================================ //
void Escreve_C_LCD (unsigned char caracter){
   RS_LCD = 1;
   RW_LCD = 0;
 
   DATA_LCD = caracter;
   EN_LCD = 1;
   Delay10TCYx (20);
   EN_LCD = 0;
   Delay10TCYx (20);
}

// ================================================================ //
// SUB-ROTINA DE ESCRITA DE FRASE NO LCD                            //
// ================================================================ //
void Escreve_LCD (rom unsigned char *caracter){
   while (*caracter != '\0'){
      Escreve_C_LCD (*caracter);
      ++caracter;
   } 
}

// ================================================================ //
// SUB-ROTINA DE INICIALIZAÇÃO DO LCD                               //
// ================================================================ //
void Inicializa_LCD (void){
   unsigned char x = 0;
   static rom unsigned char ini [] = {0x38, 0x38, 0x38, 0x0C, 0x06, 0x01, 0x00};
 
   ADCON1 = 0x0F;
   LATD = 0x00;
   LATE = LATE & 0xF8;
   TRISD = 0x00;
   TRISE = TRISE & 0xF8;
   TRISA = 0x00;			
   TRISB = 0b01110000;			
   TRISC = 0x00;			
   PORTA = 0x00;			
   PORTB = 0x00;			
   PORTC = 0b00000001;			
	
   while (ini [x] != 0x00){
      Comando_LCD (ini[x]);
      ++ x;
   } 
   
    
}

// ================================================================ //
#endif