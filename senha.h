/* 
 * File:   senha.h
 * Author: gabri
 *
 * Created on 7 de Novembro de 2019, 10:34
 */
#include"eeprom.h"
#ifndef SENHA_H
#define	SENHA_H

#ifdef	__cplusplus

    
    
#endif

    



#ifdef	__cplusplus
}
#endif

char Digito()
 {
    
    while(1){
     Delay1KTCYx (220);
     PORTBbits.RB0 = 1; PORTBbits.RB1 = 0; PORTBbits.RB2 = 0; PORTBbits.RB3 = 0;
     if(PORTBbits.RB4 == 1) { return  '1';}
     else if(PORTBbits.RB5 == 1) { return '2';}
     else if(PORTBbits.RB6 == 1) { return  '3';};
     Delay1KTCYx (1);
     
     PORTBbits.RB0 = 0; PORTBbits.RB1 = 1; PORTBbits.RB2 = 0; PORTBbits.RB3 = 0;
     if(PORTBbits.RB4 == 1) { return  '4';}
     else if(PORTBbits.RB5 == 1) { return '5';}
     else if(PORTBbits.RB6 == 1) { return  '6';};
     Delay1KTCYx (1);
     
     
     PORTBbits.RB0 = 0; PORTBbits.RB1 = 0; PORTBbits.RB2 = 1; PORTBbits.RB3 = 0;
     if(PORTBbits.RB4 == 1) { return  '7';}
     else if(PORTBbits.RB5 == 1) { return '8';}
     else if(PORTBbits.RB6 == 1) { return  '9';};
     Delay1KTCYx (1);
     
     
     PORTBbits.RB0 = 0; PORTBbits.RB1 = 0; PORTBbits.RB2 = 0; PORTBbits.RB3 = 1;
     if(PORTBbits.RB4 == 1) {return '*';}
     else if(PORTBbits.RB5 == 1) { return '0';}
     else if(PORTBbits.RB6 == 1) { return  '#';};
     Delay1KTCYx (1);
     
     /*
     PORTBbits.RB1 = 0; PORTBbits.RB2 = 1; PORTBbits.RB3 = 1; PORTBbits.RB4 = 1;
     if(PORTBbits.RB5 == 0) { return  '1';}
     else if(PORTBbits.RB6 == 0) { return '2';}
     else if(PORTBbits.RB7 == 0) { return  '3';};
     Delay1KTCYx (1);
     
     PORTBbits.RB1 = 1; PORTBbits.RB2 = 0; PORTBbits.RB3 = 1; PORTBbits.RB4 = 1;
     if(PORTBbits.RB5 == 0) { return  '4';}
     else if(PORTBbits.RB6 == 0) { return '5';}
     else if(PORTBbits.RB7 == 0) { return '6';};
     Delay1KTCYx (1);
     
     PORTBbits.RB1 = 1; PORTBbits.RB2 = 1; PORTBbits.RB3 = 0; PORTBbits.RB4 = 1;
     if(PORTBbits.RB5 == 0) { return '7';}
     else if(PORTBbits.RB6 == 0) { return '8';}
     else if(PORTBbits.RB7 == 0) { return '9';};
     Delay1KTCYx (1);
     
     PORTBbits.RB1 = 1; PORTBbits.RB2 = 1; PORTBbits.RB3 = 1; PORTBbits.RB4 = 0;
     if(PORTBbits.RB5 == 0) { return '*';}
     else if(PORTBbits.RB6 == 0) { return '0';}
     else if(PORTBbits.RB7 == 0) { return '#';};
     Delay1KTCYx (1);
      * 
      * 
      * */
     
     
     
    }
     
 }
int confereDigito(char vet[]){
    
    Inicializa_LCD();
    
    Escreve_LCD("Digite a Senha:");
    
    Posiciona_LCD(2,1);
    
    vet[0] = Digito();
    if(vet[0] == '*'){
        return 0;
    }
    Escreve_LCD("*");
    
    Posiciona_LCD(2,2);
    
    vet[1] = Digito();
    if(vet[1] == '*'){
        return 0;
    }
    Escreve_LCD("*");
    Posiciona_LCD(2,3);
    
    vet[2] = Digito();
    if(vet[2] == '*'){
        return 0;
    }
    Escreve_LCD("*");
    Posiciona_LCD(2,4);
    
    vet[3] = Digito();
    if(vet[3] == '*'){
        return 0;
    }
    Escreve_LCD("*");
    Posiciona_LCD(2,5);
    
    vet[4] = Digito();
    if(vet[4] == '*'){
        return 0;
    }
    Escreve_LCD("*");
    
    Posiciona_LCD(2,6);
    vet[5] = Digito();
    if(vet[5] == '*'){
        return 0;
    }
    Escreve_LCD("*");
    return 1;
}

int verificaSenhaMemoria(char vet[], unsigned char a){  // de acordo com o user
    // selecionado verifica na posicao de memoria correspondente
    unsigned char inicio;
    int i = 0, verifica = 0;
    for(inicio = a; inicio < a+6; inicio++, i++){
        if(Read_eep(inicio) == vet[i]){
            verifica++;
        }
    }
    if(verifica == 6){
        return 1;
    }
    else{
        return 0;
    }
}

int verificaSenha(char vet[], char a){
    int resultado = 0;
    switch (a) {
                case '1':
                   resultado = verificaSenhaMemoria(vet, 0x00);
                   break;
                case '2':
                    resultado = verificaSenhaMemoria(vet, 0x06);
                    break;
                case '3':
                    resultado = verificaSenhaMemoria(vet, 0x0C);
                    break;
                case '4':
                    resultado = verificaSenhaMemoria(vet, 0x12);
                    break;
                case '5':
                    resultado = verificaSenhaMemoria(vet, 0x18);
                    break;
                case '6':
                    resultado = verificaSenhaMemoria(vet, 0x1E);
                    break;
                case '7':
                    resultado = verificaSenhaMemoria(vet, 0x24);
                    break;
            }
    return resultado;
    
    
    /*
    if(vet[0] == '1' && vet[1] == '2' && vet[2] == '3' && vet[3] == '4' && vet[4] == '5' && vet[5] == '6' ){
        Inicializa_LCD();
        Posiciona_LCD(1,1);
        Escreve_LCD("Verificando...");
        Delay10KTCYx(100);
        Inicializa_LCD();
        Posiciona_LCD(1,1);               // Posiciona cursor na linha 1 e coluna 1
        Escreve_LCD("Senha Correta!!!");
        Posiciona_LCD(2,1);
        Delay1KTCYx (255);
        Escreve_LCD("Acesso Liberado");
        PORTCbits.RC0 = 0;
        PORTCbits.RC1 = 1;
        Delay10KTCYx (255);
    }
    else{
        Inicializa_LCD();
        Posiciona_LCD(1,1);
        Escreve_LCD("Senha Incorreta!!!");    
        PORTCbits.RC0 = 0;
        Delay1KTCYx (100);
        PORTCbits.RC0 = 1;
        Delay1KTCYx (100);
        PORTCbits.RC0 = 0;
        Delay1KTCYx (100);
        PORTCbits.RC0 = 1;
        Delay10KTCYx (50);
    }
    */
}


void pedeSenha(char vet[]){
    int result = 0;
    
    
    while(1){
        vet[6];
        result = confereDigito(vet);
        if(result == 1){
            break;
        }
    }
     
}

int pedeSenhaUserNormal(char user){
    int result = 0;
    char vet[6];
    
    while(1){
        vet[6];
        result = confereDigito(vet);
        if(result == 1){
            break;
        }
    }
     
    return verificaSenha(vet, user);
}


int confirmaReiniciar(){
    char verifica;
    Inicializa_LCD();
    Posiciona_LCD(1,1);
    Escreve_LCD("Tem certeza que");
    Posiciona_LCD(2,1);
    Escreve_LCD("deseja reiniciar");
    Delay10KTCYx (50);
    
    do{
        Inicializa_LCD();
        Posiciona_LCD(1,1);
        Escreve_LCD("1- SIM  2-NAO");
        Posiciona_LCD(2,1);
        verifica = Digito();
        Escreve_C_LCD(verifica);
        Delay1KTCYx (50);
        if(verifica == '1'){
            return 1;
        }
        else if(verifica == '2'){
            return 2;
        }
        else{ 
            Escreve_LCD("Opção incorreta");
        }
    }while(1);
     
}


void trocarSenhaRoot(){   // para a primeira vez que ligar o pic
    char vet[6], vet2[6];
    int i = 0;
    Delay10KTCYx (50);
    while(i == 0){
        Inicializa_LCD();
        Posiciona_LCD(1,1);
        Delay10KTCYx (50);
        Escreve_LCD("DIGITE A NOVA");
        Posiciona_LCD(2,1);
        Escreve_LCD("SENHA DO ROOT");
        Delay10KTCYx (50);
        pedeSenha(vet);
        Inicializa_LCD();
        Posiciona_LCD(1,1);
        Escreve_LCD("Digite novamente");
        pedeSenha(vet2);
        if(vet[0] == vet2[0] && vet[1] == vet2[1] && vet[2] == vet2[2]){
            if(vet[3] == vet2[3] && vet[4] == vet2[4] && vet[5] == vet2[5]){
                i = 1;
            }
        }else{
            Inicializa_LCD();
            Posiciona_LCD(1,1);
            Escreve_LCD("Senhas não");
            Posiciona_LCD(2,1);
            Escreve_LCD("correspondem!");
            Delay10KTCYx (50);
        }
    }
    // grava a senha que foi digitada pro root   
    Write_eep( 0x00, vet[0] );
    Write_eep( 0x01, vet[1] );
    Write_eep( 0x02, vet[2] );
    Write_eep( 0x03, vet[3] );
    Write_eep( 0x04, vet[4] );
    Write_eep( 0x05, vet[5] );
    Write_eep( 0xFF, '1' );
    Write_eep( 0xFE, '1' );
    Inicializa_LCD();
    Posiciona_LCD(1,1);
    Escreve_LCD("Senha salva com");
    Posiciona_LCD(2,1);
    Escreve_LCD("sucesso!");
    Delay10KTCYx (50);
}

void cadastraSenha(char senha[]){
    int result = 0;
    char vet[6];
    
    while(1){
        vet[6];
        result = confereDigito(vet);
        if(result == 1){
            break;
        }
    }
     
    senha[0] = vet[0];
    senha[1] = vet[1];
    senha[2] = vet[2];
    senha[3] = vet[3];
    senha[4] = vet[4];
    senha[5] = vet[5];
}

void cadastraUsuarioMemoria(unsigned char a){
    unsigned char inicio;
    int i = 0;
    char vet[];
    Inicializa_LCD();
    Posiciona_LCD(1,1);
    Escreve_LCD("Cadastro do user");
    Posiciona_LCD(2,1);
    Escreve_C_LCD(Read_eep(0xFE));
    Delay10KTCYx (100);
    
    Inicializa_LCD();
    Posiciona_LCD(1,1);
    Escreve_LCD("Cadastro senha");
    Delay10KTCYx (100);
    
    cadastraSenha(vet);
    
    for(inicio = a; inicio < a+6; inicio++, i++){
        Write_eep(inicio , vet[0] );
    }
    
}

void cadastrarUsuario(){
    switch (Read_eep(0xFE)){
        case '1':
            cadastraUsuarioMemoria(0x06);
            Write_eep( 0xFE, '2' );  // atualiza a quantidade de usuarios
            break;
        case '2':
            cadastraUsuarioMemoria(0x0C);
            Write_eep( 0xFE, '3' );
            break;
        case '3':
            cadastraUsuarioMemoria(0x12);
            Write_eep( 0xFE, '4' );
            break;
        case '4':
            cadastraUsuarioMemoria(0x18);
            Write_eep( 0xFE, '5' );
            break;
        case '5':
            cadastraUsuarioMemoria(0x1E);
            Write_eep( 0xFE, '6' );
            break;
        case '6':
            cadastraUsuarioMemoria(0x24);
            Write_eep( 0xFE, '7' );
            break;
        case '7':
            Inicializa_LCD();
            Posiciona_LCD(1,1);
            Escreve_LCD("numero maximo de");
            Posiciona_LCD(2,1);
            Escreve_LCD("users atingido");
            Delay10KTCYx (100);
            break;
    }
}

#endif	/* SENHA_H */

