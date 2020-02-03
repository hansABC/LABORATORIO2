/*
 * File:   Laboratorio2_1.c
 * Author: hansb
 *
 * Created on 31 de enero de 2020, 02:30 PM
 */

#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

#define _XTAL_FREQ 8000000      //Frecuencia para la función delay

#include <xc.h>
#include<stdint.h>

//******************************************************************************************************
//                  PROTOTPOS DE FUNCIONES
//*****************************************************************************************************

void iniciar(void);



uint8_t BANDERAboton;
uint8_t varCONTADOR;



//*******************************************************************************************************
//                  INTERRUPCIONES
//*******************************************************************************************************

void __interrupt()isr(void){
    
    if(RBIF==1){
        RBIF=0;
        if(BANDERAboton==0){
            if(PORTBbits.RB6==1){
                BANDERAboton=1;
                varCONTADOR++;
            }
            if(PORTBbits.RB1==1){
                BANDERAboton=1;
                varCONTADOR--;
            }
            
        }    
        
    }
    
    
}

//*****************************************************************************************************
//                  MAIN PRINCIPAL
//*****************************************************************************************************


void main(void) {
    iniciar();
    PORTA=0;
    PORTD=0;
    PORTC=0;
    PORTB=0;
    PORTE=0;
    BANDERAboton=0;
    varCONTADOR=0;
    
    
    //ADCON0bits.GO_nDONE=1;
    while(1){
        BANDERAboton=0;                                         //BANDERA                                        
        PORTA=varCONTADOR;                                      //ENVIA LA VARAIBLE CONTADOR AL PUERTO A (LEDS)
        
    }
    
    return;
}





//****************************************************************************************************
//              FUNCIONES
//****************************************************************************************************
void iniciar(void){
    TRISC=0;                //PUERTOS COMO SALIDAS
    TRISA=0;
    TRISB=0b11111111;
    OSCCON=0b01110001;      //FRECUENCIA DE 8MHZ Y UTILIZACIÓN DE RELOJ INTERNO
    TRISEbits.TRISE0=0;		//PIN PARA LA ALARMA 
    TRISEbits.TRISE1=0;		//PIN PARA TRANSISTOR 1
    TRISEbits.TRISE2=0;		//PIN PARA TRANSISTOR 2
    ANSEL = 0;                //PINES DEL REGISTRO ANSEL CONFIGURADORS COMO DIGITALES
    ANSELH = 0;		//PIN RB5 PARA EL POTENCIOMETRO
    ANSELHbits.ANS13 = 1;
    IOCB = 0b01000010;        //INTERRUPCIONES EN LOS BOTONES B0 Y B1
    RBIF = 0;
    INTCON = 0b11101000;		//HABILITAR INTERUPCCIONES 
    
    PORTA=0;
    PORTD=0;
    PORTC=0;
    PORTB=0;
    PORTE=0;
}

