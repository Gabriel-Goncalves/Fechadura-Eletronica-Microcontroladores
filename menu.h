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

void liberarAcesso(){
        
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
        
        PORTAbits.RA3 = 1;    
        Delay10KTCYx(255);
        Delay10KTCYx(255);
        PORTAbits.RA3 = 0;
         
        Delay10KTCYx (255);
        
        
    
}

void negarAcesso(){
    
        Inicializa_LCD();
        Posiciona_LCD(1,1);
        Escreve_LCD("Senha Incorreta!!!");
        
        PORTCbits.RC1 = 1;    
        Delay10KTCYx(100);
        PORTCbits.RC1 = 0; 
        Delay10KTCYx (100);
        PORTCbits.RC1 = 1;    
        Delay10KTCYx(150);
        PORTCbits.RC1 = 0; 
        Delay10KTCYx (255);
    
}


void menuRoot(){
    
    //entrar aqui apenas depois de verificar senha root
    
    char vet[6];
    char saiLoop = 't';
    do{
        Inicializa_LCD();
        Posiciona_LCD(1,1);               //Posiciona cursor na linha 1 e coluna 1
        Escreve_LCD("1-abrir 3-reset");
        Posiciona_LCD(2,1);
        Escreve_LCD("2-cadastrar user");
        switch (Digito()) {
        case '1':
            pedeSenha(vet);
            if(verificaSenha(vet, '1') == 1){
                liberarAcesso();
            }else{
                negarAcesso();
            }
            saiLoop = 'g';
           break;
        case '2':
            pedeSenha(vet);
            if(verificaSenha(vet, '1') == 1){
                cadastrarUsuario();;
            }else{
                negarAcesso();
            }
            saiLoop = 'g';
            break;
        case '3':
            //arrumar para pedir senha para reiniciar
            reiniciarConfiguracaoInicial();
            saiLoop = 'g';
            break;
        default:
           Inicializa_LCD();
           Posiciona_LCD(1,1);               //Posiciona cursor na linha 1 e coluna 1
           Escreve_LCD("Opcao invalida");
           Posiciona_LCD(2,1);
           Escreve_LCD("Digite novamente");
           Delay10KTCYx(170);
        }
    }while(saiLoop == 't');
 
    Delay10KTCYx(100);
    
    // criar as fun�oes para abri e cadastrar
}


void iniciar(){
    char saiLoop = 't';
    if(verificaEEPROM() == 1){
        // Menu para primeiro acesso
        char vet[6];
        Inicializa_LCD();
        Posiciona_LCD(1,1);               //Posiciona cursor na linha 1 e coluna 1
        Escreve_LCD("BEM VINDO!!!");
        Posiciona_LCD(2,1);  
        Escreve_LCD("Primeiro acesso");
        Delay10KTCYx (200);
        Delay10KTCYx (90);
        
        Inicializa_LCD();
        Posiciona_LCD(1,1);               //Posiciona cursor na linha 1 e coluna 1
        Escreve_LCD("Digite a senha");
        Posiciona_LCD(2,1);  
        Escreve_LCD("Padrao");
        Delay10KTCYx (180);
        Delay10KTCYx (100);
        
        pedeSenha(vet);
        if(verificaSenhaPadrao(vet)){
            Inicializa_LCD();
            Escreve_LCD("Senha correta!!!");
            Posiciona_LCD(2,1);  
            Escreve_LCD("Primeiro acesso");
            Delay10KTCYx (90);
            trocarSenhaRoot();
        }else{
            negarAcesso();
        }
        
        
        
    }else{
        //segundo acesso em diante
        do{
            char user;
            Inicializa_LCD();
            Posiciona_LCD(1,1);               //Posiciona cursor na linha 1 e coluna 1
            Escreve_LCD("Selecione o User");
            Posiciona_LCD(2,1);
            Escreve_LCD("1-2-3-4-5-6-7");
            user = Digito();
            Delay10KTCYx(10);
            switch (user) {
                case '1':
                   menuRoot();
                   saiLoop = 'f';
                   break;
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                    if(pedeSenhaUserNormal(user) == 1){  //arrumar
                        liberarAcesso();
                    }else{
                        negarAcesso();
                    }
                    saiLoop = 'f';
                    break;
                default:
                   Inicializa_LCD();
                   Posiciona_LCD(1,1);               //Posiciona cursor na linha 1 e coluna 1
                   Escreve_LCD("Opcao invalida");
                   Posiciona_LCD(2,1);
                   Escreve_LCD("Digite novamente");
                   Delay10KTCYx(150);
            }
        }while(saiLoop == 't');
        
        
        
        
        //com o valor de user pedir e comparar a senha com a posicao de memoria
        // de cada um de acordo com o user escolhido
        
    }
}




#endif	/* MENU_H */

