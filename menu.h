/* 
 * File:   menu.h
 * Author: gabri
 *
 * Created on 7 de Novembro de 2019, 13:01
 */

#ifndef MENU_H
#define	MENU_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

void iniciar(){
    
    if(verificaEEPROM() == 1){
        // Menu para primeiro acesso
        Inicializa_LCD();
        Posiciona_LCD(1,1);               //Posiciona cursor na linha 1 e coluna 1
        Escreve_LCD("BEM VINDO!!!");
        Posiciona_LCD(2,1);  
        Escreve_LCD("Primeiro acesso");
        Delay10KTCYx (50);
        trocarSenhaRoot();
    }else{
        //segundo acesso em diante
        Inicializa_LCD();
        Posiciona_LCD(1,1);               //Posiciona cursor na linha 1 e coluna 1
        Escreve_LCD("Segundo acesso");
        Delay10KTCYx(100);
    }
}
#endif	/* MENU_H */

