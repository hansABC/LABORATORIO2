#include<stdint.h>
#include<pic16f887.h>
#include "sevenSEG.h"

//********************************************************************************************
//              CONVERSIÓN BIN A HEX
//*******************************************************************************************

uint8_t CONVERSION(uint8_t var1){
    uint8_t res = 0;
    switch(var1){
        case 0:
            res=0b011111110;
            break;
            
        case 1:
            res = 0b00011000;
            break;
        
        case 2:
            res = 0b01101101;
            break;
        
        case 3:
            res = 0b00111101;
            break;
            
        case 4:
            res = 0b00011011;
            break;
            
        case 5:
            res = 0b00110111;
            break;
            
        case 6:
            res = 0b01110011;
            break;
            
        case 7:
            res = 0b00011100;
            break;
            
        case 8:
            res = 0b01111111;
            break;
            
        case 9:
            res = 0b00011111;
            break;
            
        case 10:
            res = 0b01011111;
            break;
            
        case 11:
            res = 0b01111111;
            break;
            
        case 12:
            res = 0b01100110;
            break;
            
        case 13:
            res = 0b01111001;
            break;
            
        case 14:
            res = 0b01100111;
            break;
            
        case 15:
            res = 0b01000111;
            break;
             
    }
    return res;
}
