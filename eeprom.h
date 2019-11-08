/* 
 * File:   eeprom.h
 * Author: gabri
 *
 * Created on 7 de Novembro de 2019, 11:17
 */


#ifndef EEPROM_H
#define	EEPROM_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif
unsigned char Read_eep( unsigned char badd ){ // (le na pos badd)
 EEADR = badd;
 EECON1bits.CFGS = 0;
 EECON1bits.EEPGD = 0;
 EECON1bits.RD = 1;
 return ( EEDATA ); // return with read byte
}

void Write_eep( unsigned char badd,unsigned char bdat ){ // passa a (pos,valor)
    char GIE_BIT_VAL = 0;
    EEADR = badd;
    EEDATA = bdat;
    EECON1bits.EEPGD = 0;
    EECON1bits.CFGS = 0;
    EECON1bits.WREN = 1;
    GIE_BIT_VAL = INTCONbits.GIE;
    INTCONbits.GIE = 0;
    EECON2 = 0x55;
    EECON2 = 0xAA;
    EECON1bits.WR = 1;
    while(EECON1bits.WR); //Wait till the write completion
    INTCONbits.GIE = GIE_BIT_VAL;
    EECON1bits.WREN = 0;
}

int verificaEEPROM(){  // verificação se é o primeiro acesso
    if(Read_eep(0xFF) == '9'){ 
        return 1;  // Nunca foi acessado
    }else{ return 0;}  // primeiro acesso
}

void reiniciaEEPROM(){
    unsigned char i;
    Write_eep( 0x00, '1' );
    Write_eep( 0x01, '2' );
    Write_eep( 0x02, '3' );
    Write_eep( 0x03, '4' );
    Write_eep( 0x04, '5' );
    Write_eep( 0x05, '6' );
    Write_eep( 0xFF, '9' );  // dizer que nunca foi acessado antes
    for(i = 0x06; i < 0xFF; i++){
        Write_eep( i, 0xFF );
    }
}

int reiniciarConfiguracaoInicial(){   // reiniciar configuracao inicial
    // para o que o root tenha senha 123456
    int confirmacao = confirmaReiniciar();
    if(confirmacao == 1){
        reiniciaEEPROM();
        return 1;
    }
    else{
        return 0;
    }
}

void reiniciarPadrao(){ // tudo FF como se fosse um pic novo
    unsigned char i; 
    for(i = 0x00; i < 0xFF; i++){
        Write_eep( i, 0xFF );
    }
}


#endif	/* EEPROM_H */

