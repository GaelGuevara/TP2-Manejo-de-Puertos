/*13. Diseñar una solución programable de manera tal que en el Puerto A se refleje el valor
del Puerto B menos uno.
*/

#include "MKL25Z4.h"

int main(){
    
    SIM -> SCGC5|=SIM_SCGC5_PORTA_MASK|SIM_SCGC5_PORTB_MASK;
    PORTB -> PDDR|=0X00000000;
    PORTA -> PDDR|=0XFFFFFFFF;

    while (1){
        uint32_t PuertoB= ((PTB -> PDIR) - 1);
        PTA -> PDOR|= PuertoB;
    }
}