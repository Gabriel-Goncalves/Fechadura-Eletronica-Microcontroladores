/*********************************************************************
Nome do arquivo:	QUESTAO-01.c            
Data:	    		21 de setembro de 2019          
Versao:				1.0                              
MPLABx: 			v5.25 
Professor:      	Carl�cio Silva              
Aluno:              
Matr�cula:   
Observa��es:
 1. Os alunos t�m at� as 21:50 para enviar o arquivo do projeto compactado, 
    isso dever� ser feito da seguinte forma: O arquivo FORMAL_N1 que consta 
    no Desktop dever� ser renomeado com:
    PRIMEIRO_NOME_DO_ALUNO_EM_MAI�SCULO|MATR�CULA.
2. Os alunos que enviarem os arquivos ap�s as 21:50 ser�o penalizados com
    1 (um) d�cimo para cada minuto de atraso e se ultrapassar as 22:00 tais 
    alunos ser�o penalizados com 5 (d�cimos) al�m das penaliza��es anteriores.        
*********************************************************************/
#include <p18f4550.h>		//diretiva de compila��o
#include "MCC18_18F4550.h"
#include <delays.h>

//********************************************************************
//vari�veis globais
 
//********************************************************************

//********************************************************************
//prot�tipos de fun��es
 void Inic_Regs(void);
 
//********************************************************************
 
//fun��o principal 
void main(void)										
{	   
    //vari�veis locais
    
    //inicializa��o dos SFRs
	Inic_Regs();
    
    //loop infinito
	while (1)                   
	{
        
	}
}
/*******************************************************************
Esta funcao inicializa os resgistradores SFRs.*/
 void Inic_Regs(void)
{
	TRISA = 0xXX;			//configura PORTA   1 para entrada e 0 para saida
	TRISB = 0xXX;			//configura PORTB
	TRISC = 0xXX;			//configura PORTC
	TRISD = 0xXX;			//configura PORTD
	TRISE = 0xXX;			//configura PORTE
	
	ADCON1 = 0xXX;			//configura pinos como digitais
	
	PORTA = 0xXX;			//inicializa PORTA   como as portas ir�o iniciar? se for em nivel baixo 0 em alto 1
	PORTB = 0xXX;			//inicializa PORTB
	PORTC = 0xXX;			//inicializa PORTC
	PORTD = 0xXX;			//inicializa PORTD
	PORTE = 0xXX;			//inicializa PORTE
//********************************************************************
}
