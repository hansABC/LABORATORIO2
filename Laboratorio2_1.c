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
#include <pic16f887.h>
#include"sevenSEG.h"
#include"ConfADC.h"

//******************************************************************************************************
//                  PROTOTPOS DE FUNCIONES
//*****************************************************************************************************

void iniciar(void);



uint8_t BANDERAboton;
uint8_t varCONTADOR;
uint8_t UNIDADES;
uint8_t DECENAS;
uint8_t VAR1;
uint8_t AND=0b00001111;
uint8_t TEMP;
uint8_t RES1;
uint8_t RES2;
uint8_t BANmul;
uint8_t BANDERAPROPIA;



//*******************************************************************************************************
//                  INTERRUPCIONES
//*******************************************************************************************************

void __interrupt()isr(void){
    
    if(RBIF==1){                                    //INTERRUPCIÓN PARA REALIZAR EL CONTADOR
        RBIF=0;
        if(BANDERAboton==0){
            if(PORTBbits.RB6==1){                   //REVISAR SI EL BOTON DE INCREMENTO FUE PRESIONADO
                BANDERAboton=1;
                varCONTADOR++;                      //INCREMENTAR EL CONTADOR
            }
            if(PORTBbits.RB1==1){                   //REVISAR SI EL BOTON DE DECREMENTO FUE PRESIONADO
                BANDERAboton=1;
                varCONTADOR--;                      //DECREMENTAR EL CONTADOR
            }
            
        }    
        
    }
    
    if(ADIF==1){                                    //INTERRUPCIÓN DEL ADC                  
        ADIF=0;                                     //REVISAR LA BANDERA
        if(ADCON0bits.GO==0){
            VAR1 = ADRESH;                          //GUARDAR EL ADRESH EN UNA VARIABLE YA QUE LUEGO SERVIRÁ PARA HACER LA COMPARACIÓN CON EL CONTADOR
            UNIDADES=VAR1&AND;                      //DIVIR EL ADRESH EN DOS VARIABLES DIFERENTES PARA ENVIAR A LOS DOS DISPLAYS
            DECENAS=VAR1>>4;
        }
        
    }
    
    if(T0IF==1){                                    //INTERRUPCIÓN DEL TIMER0  
        T0IF=0;                                    //APAGAR BANDERA DE INTERRUPCIÓN                                                  
        TMR0=68;                                    //CARGAR EL TIMER 0 CON ESTE VALOR PARA TENER UN OVERFLOW CADA 3MS
        TEMP++;                                     //AUMENTAR UNA VARIABLE 
        }
    }
    
    
    


//*****************************************************************************************************
//                  MAIN PRINCIPAL
//*****************************************************************************************************


void main(void) {
    iniciar();
    ADC(41);                                        //CONFIGURACIÓN INICIAL DEL ADC
    PORTA=0;
    PORTD=0;
    PORTC=0;
    PORTB=0;
    PORTE=0;
    BANDERAboton=0;
    varCONTADOR=0;
    UNIDADES=0;
    DECENAS=0;
    TEMP = 0;
    VAR1=0;
    BANmul=0;
    BANDERAPROPIA = 0;
    

    while(1){
        BANDERAboton=0;                                         //BANDERA DE ANTIREBOTE                                      
        PORTA=varCONTADOR;                                      //ENVIA LA VARAIBLE CONTADOR AL PUERTO A (LEDS)
        ADCON0bits.GO=1;                                        //QUE SIEMPRE ESTE REALIZANDO LA CONVERSIÓN
        BANmul=TEMP%2;                                          //ME REGRESA SOLO VALORES ENTRE 0 Y 1
        
        
        if(BANmul==0){                                        //MULTIPLEXEO
            PORTEbits.RE2=0;                                 //ENCENDER Y APAGAR LOS TRANSISTORES CORRESPONDIENTES DE CADA DISPLAY
            RES1 = CONVERSION(UNIDADES);
            PORTC=RES1;                                      //ENVIAR EL RESULTADO DE LA CONVERSIÓN A HEX AL PORTC
            PORTEbits.RE1=1;
        }
        if(BANmul==1){      
            PORTEbits.RE1=0;
            RES2 = CONVERSION(DECENAS);
            PORTC=RES2;
            PORTEbits.RE2=1;
        }  
        
        if(VAR1>varCONTADOR){                                   //COMPARA EL CONTADOR CON EL ADC
            PORTEbits.RE0=1;                                 //ENCENDER LED
        }else{
            PORTEbits.RE0=0;                                 //SI NO ES MAYOR EL VALOR DEL ADC, SE MANTIENE APAGADA LA LED
        }
        
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
    ANSEL = 0;              //PINES DEL REGISTRO ANSEL CONFIGURADORS COMO DIGITALES
    ANSELH = 0;             
    ANSELHbits.ANS13 = 1;   //PIN RB5 PARA EL POTENCIOMETRO
    IOCB = 0b01000010;      //INTERRUPCIONES EN LOS BOTONES B6 Y B1
    RBIF = 0;
    INTCON = 0b11101000;	//HABILITAR INTERUPCCIONES 
    OPTION_REG	 = 0x84;    //CONFIGURACION DEL TIMER0
    TMR0 = 68;              //CONFIGURACIÓN DEL TIMER0 PARA 3ms

    
    PORTA=0;
    PORTD=0;
    PORTC=0;
    PORTB=0;
    PORTE=0;
}

