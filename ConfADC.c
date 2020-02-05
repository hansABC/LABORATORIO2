#include <pic16f887.h>
#include <stdint.h>
#include "sevenSEG.h"

//*****************************************************************************************************
//                      CONFIGURACIÓN ADC
//*****************************************************************************************************

void ADC (uint8_t num){
    switch(num){
        case 0:
            PIE1 = 0b01000000;
            ADCON0 = 0b00000011;            //FOSC/2 Y AN0
            ADCON1 = 0;                     //JUSTIFICACIÓN IZQUIERDA
            break;
            
        case 1:
            PIE1 = 0b01000000;
            ADCON0 = 0b01000011;            //FOSC/8 Y AN0
            ADCON1 = 0;                     //JUSTIFICACIÓN IZQUIERDA
            break;
            
        case 2:
            PIE1 = 0b01000000;              
            ADCON0 = 0b10000011;            //FOSC/32 Y AN0
            ADCON1 = 0;                     //JUSTIFICACIÓN IZQUIERDA
            break;
            
        case 3:
            PIE1 = 0b01000000;
            ADCON0=0b00000111;              //FOSC/2 Y AN1
            ADCON1 = 0;                     //JUSTIFICACIÓN IZQUIERDA
            break;
            
        case 4:
            PIE1 = 0b01000000;
            ADCON0 = 0b01000111;            //FOSC/8 Y AN1
            ADCON1 = 0;                     //JUSTIFICACIÓN IZQUIERDA
            break;
            
        case 5:
            PIE1 = 0b01000000;
            ADCON0 = 0b10000111;            //FOSC/32 Y AN1
            ADCON1 = 0;                     //JUSTIFIACIÓN IZQUIERDA
            break;
            
        case 6:
            PIE1 = 0b01000000;
            ADCON0=0b00001011;              //FOSC/2 Y AN2
            ADCON1 = 0;                     //JUSTIFICACIÓN IZQUIERDA
            break;
            
        case 7:
            PIE1 = 0b01000000;
            ADCON0 = 0b01001011;            //FOSC/8 Y AN2
            ADCON1=0;                       //JUSTIFICACIÓN IZQUIERDA
            break;
            
        case 8:
            PIE1 = 0b01000000;
            ADCON0 = 0b10001011;            //FOS/32 Y AN2
            ADCON1 = 0;                     //JUSTIFICACIÓN IZQUIERDA
            break;
            
        case 9:
            PIE1 = 0b01000000;
            ADCON0 = 0b00001111;            //FOSC/2 Y AN3
            ADCON1 = 0;                     //JUSTIFICACIÓN IZQUIERDA
            break;
            
        case 10:
            PIE1 = 0b01000000;
            ADCON0 = 0b01001111;            //FOSC/8 Y AN3
            ADCON1 = 0;                     //JUSTIFICACIÓN IZQUIERDA
            break;
            
        case 11:
            PIE1 = 0b01000000;
            ADCON0 = 0b10001111;            //FOS/32 Y AN3
            ADCON1 = 0;                     //JUSTIFICACIÓN IZQUIERDA
            break;
            
        case 12:
            PIE1 = 0b01000000;
            ADCON0= 0b00010011;             //FOSC/2 Y AN4
            ADCON1= 0;                      //JUSTIFICACIÓN IZQUIERDA
            break;
            
        case 13:
            PIE1 = 0b01000000;
            ADCON0 = 0b01010011;            //FOSC/8 Y AN4
            ADCON1 = 0;                     //JUSTIFICACIÓN IZQUIERDA
            break;
            
        case 14:
            PIE1 = 0b01000000;
            ADCON0 = 0b10010011;            //FOSC/32 Y AN4
            ADCON1 = 0;                     //JUSTIFICACIÓN IZQUIERDA
            break;
            
        case 15:
            PIE1 = 0b01000000;
            ADCON0 = 0b00010111;            //FOSC/2 Y AN5
            ADCON1 = 0;                     //JUSTIFICACIÓN IZQUIERDA
            break;
            
        case 16:
            PIE1 = 0b01000000;
            ADCON0 = 0b01010111;            //FOSC/8 Y AN5
            ADCON1 = 0;                     //JUSTIFICACIÓN IZQUIERDA
            break;
            
        case 17:
            PIE1 = 0b01000000;
            ADCON0 = 0b10010111;            //FOSC/32 Y AN5
            ADCON1 = 0;                     //JUSTIFICACIÓN IZQUIERDA
            break;
            
        case 18:
            PIE1 = 0b01000000;
            ADCON0 = 0b00011011;            //FOSC/2 Y AN6
            ADCON1 = 0;                     //JUSTIFICACIÓN IZQUIERDA
            break;
            
        case 19:
            PIE1 = 0b01000000;
            ADCON0 = 0b01011011;            //FOSC/8 Y AN6
            ADCON1 = 0;                     //JUSTIFICACIÓN IZQUIERDA
            break;
            
        case 20:
            PIE1 = 0b01000000;
            ADCON0 = 0b10011011;            //FOSC/32 Y AN6
            ADCON1 = 0;                     //JUSTIFICACIÓN IZQUIERDA
            break;
            
        case 21:
            PIE1 = 0b01000000;
            ADCON0 = 0b00011111;            //FOSC/2 Y AN7
            ADCON1 = 0;                     //JUSTIFICACIÓN IZQUIERDA
            break;
            
        case 22:
            PIE1 = 0b01000000;
            ADCON0 = 0b01011111;            //FOSC/8 Y AN7
            ADCON1 = 0;                     //JUSTIFICACIÓN IZQUIERDA
            break;
            
        case 23:
            PIE1 = 0b01000000;
            ADCON0 = 0b10011111;            //FOSC/32 Y AN7
            ADCON1 = 0;                     //JUSTIFICACIÓN IZQUIERDA
            break;
            
        case 24:
            PIE1 = 0b01000000;
            ADCON0 = 0b00100011;            //FOSC/2 Y AN8
            ADCON1 = 0;                     //JUSTIFICACIÓN IZQUIERDA
            break;
            
        case 25:
            PIE1 = 0b01000000;
            ADCON0 = 0b01100011;            //FOSC/8 Y AN8
            ADCON1 = 0;                     //JUSTIFICACIÓN IZQUIERDA
            break;
            
        case 26:
            PIE1 = 0b01000000;
            ADCON0 = 0b10100011;            //FOSC/32 Y AN8
            ADCON1 = 0;                     //JUSTIFICACIÓN IZQUIERDA
            break;
            
        case 27:
            PIE1 = 0b01000000;
            ADCON0 = 0b00100111;            //FOSC/2  Y AN9
            ADCON1 = 0;                     //JUSTIFICACIÓN IZQUIERDA
            break;
            
        case 28:
            PIE1 = 0b01000000;
            ADCON0 = 0b01100111;            //FOSC/8 Y AN9
            ADCON1 = 0;                     //JUSTIFICACIÓN IZQUIERDA
            break;
            
        case 29:
            PIE1 = 0b01000000;
            ADCON0 = 0b10100111;            //FOSC/32 Y AN9
            ADCON1 = 0;                     //JUSTIFICACIÓN IZQUIERDA
            break;
            
        case 30:
            PIE1 = 0b01000000;
            ADCON0 = 0b00101011;            //FOSC/2 Y AN10
            ADCON1 = 0;                     //JUSTIFICACIÓN IZQUIERDA
            break;
            
        case 31:
            PIE1 = 0b01000000;
            ADCON0 = 0b01101011;            //FOSC/8 Y AN10
            ADCON1 = 0;                     //JUSTIFICACIÓN IZQUIERDA
            break;
            
        case 32:
            PIE1 = 0b01000000;
            ADCON0 = 0b10101011;            //FOSC/32 Y AN10
            ADCON1 = 0;                     //JUSTIFICACIÓN IZQUIERDA
            break;
            
        case 33:
            PIE1 = 0b01000000;
            ADCON0 = 0b00101111;            //FOSC/2 Y AN11
            ADCON1 = 0;                     //JUSTIFICADO A LA IZQUIERDA
            break;
            
        case 34:
            PIE1 = 0b01000000;
            ADCON0 = 0b01101111;            //FOSC/8 Y AN11
            ADCON1 = 0;                     //JUSTIFICACIÓN IZQUIERDA
            break;
            
        case 35:
            PIE1 = 0b01000000;
            ADCON0 = 0b10101111;            //FOSC/32 Y AN11
            ADCON1 = 0;                     //JUSTIFICACIÓN IZQUIERDA
            break;
            
        case 36:
            PIE1 = 0b01000000;
            ADCON0 = 0b00110011;            //FOSC/2 Y AN12
            ADCON1 = 0;                     //JUSTIFICACIÓN IZQUIERDA
            break;
            
        case 37:
            PIE1 = 0b01000000;
            ADCON0 = 0b01110011;            //FOSC/8 Y AN12
            ADCON1 = 0;                     //JUSTIFICACIÓN IZQUIERDA
            break;
            
        case 38:
            PIE1 = 0b01000000;
            ADCON0 = 0b10110011;            //FOSC/32 Y AN12
            ADCON1 = 0;
            break;
            
        case 39:
            PIE1 = 0b01000000;
            ADCON0 = 0b00110111;            //FOSC/2 Y AN13
            ADCON1 = 0;                     //JUSTIFICACIÓN IZQUIERDA
            break;
            
        case 40:
            PIE1 = 0b01000000;
            ADCON0 = 0b01110111;            //FOSC/8 T AN13
            ADCON1 = 0;                     //JUSTIFICACIÓN IZQUIERDA
            break;
            
        case 41:
            PIE1 = 0b01000000;
            ADCON0 = 0b10110111;            //FOSC/32 Y AN13
            ADCON1 = 0;                     //JUSTIFICACIÓN IZQUIERDA
            break;
            
    }
}
