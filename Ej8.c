/*8. Diseñar una solución programable de manera tal que en el Puerto A se obtenga el
resultado de la operación xor entre el Puerto B y el literal 0x23.
*/

#include "MKL25Z4.h"

int main(){
    
    SIM -> SCGC5|=SIM_SCGC5_PORTA_MASK|SIM_SCGC5_PORTB_MASK;
    PORTB -> PDDR|=0X00000000;
    PORTA -> PDDR|=0XFFFFFFFF;

    while (1){
        uint32_t PuertoB= ((PTB -> PDIR) ^ 0x23);
        PTA -> PDOR|= PuertoB;
    }  
}