#include"head.h"
void delay_ms(unsigned int ms){
        T0PR=15000*ms-1;
        T0TC=T0PC=0;
        T0TCR=1;
        while(T0TC<1);
        T0TCR=0;
}

