/*17. Diseñar una solución programable de manera tal que las salidas A0, A2, A4 y A6 se
activen si B0 está inactivo; y las salidas A1, A3, A5 y A7 se activen si B0 está activo.
*/

#include "MKL25Z4.h"
int outs1[4]={0,2,4,6};
int outs2[4]={1,3,5,7};
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