/*18. Diseñar una solución programable de manera tal que las salidas A0, A1, A2 y A3 se
activen si B0 está activo; y las salidas A4, A5, A6 y A7 se activen si B0 está inactivo.
*/

#include "MKL25Z4.h"
int outs1[4]={0,1,2,3};
int outs2[4]={4,5,6,7};
int i;

int main(){
    
    SIM -> SCGC5|=SIM_SCGC5_PORTA_MASK|SIM_SCGC5_PORTB_MASK;
    PORTB -> PDDR|=0X00000000;
    PORTA -> PDDR|=0XFFFFFFFF;

    while (1){
        if((PTB -> PDIR&(1u<<0)) == 0){
            for(i=0;i<4;i++){
                PTA -> PSOR|=(outs1[i]u<<0);
                PTA -> PSOR|=(outs2[i]u<<1);
            }
        }else{
            for(i=0;i<4;i++){
                PTA -> PSOR|=(outs1[i]u<<1);
                PTA -> PSOR|=(outs2[i]u<<0);
            }
        }
    }
}