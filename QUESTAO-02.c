/*********************************************************************
Nome do arquivo:	QUESTAO-01.c            
Data:	    		21 de setembro de 2019          
Versao:				1.0                              
MPLABx: 			v5.25 
Professor:      	Carlúcio Silva              
Aluno:              
Matrícula:   
Observações:
 1. Os alunos têm até as 21:50 para enviar o arquivo do projeto compactado, 
    isso deverá ser feito da seguinte forma: O arquivo FORMAL_N1 que consta 
    no Desktop deverá ser renomeado com:
    PRIMEIRO_NOME_DO_ALUNO_EM_MAIÚSCULO|MATRÍCULA.
2. Os alunos que enviarem os arquivos após as 21:50 serão penalizados com
    1 (um) décimo para cada minuto de atraso e se ultrapassar as 22:00 tais 
    alunos serão penalizados com 5 (décimos) além das penalizações anteriores.        
*********************************************************************/
#include <p18f4550.h>		//diretiva de compilação
#include "MCC18_18F4550.h"
#include <delays.h>

//********************************************************************
//variáveis globais
 
//********************************************************************

//********************************************************************
//protótipos de funções
 void Inic_Regs(void);
 
//********************************************************************
 
//função principal 
void main(void)										
{	   
    //variáveis locais
    
    //inicialização dos SFRs
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
	
	PORTA = 0xXX;			//inicializa PORTA   como as portas irão iniciar? se for em nivel baixo 0 em alto 1
	PORTB = 0xXX;			//inicializa PORTB
	PORTC = 0xXX;			//inicializa PORTC
	PORTD = 0xXX;			//inicializa PORTD
	PORTE = 0xXX;			//inicializa PORTE
//********************************************************************
}
