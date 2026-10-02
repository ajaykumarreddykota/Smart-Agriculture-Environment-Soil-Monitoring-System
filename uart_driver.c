#include"head.h"
void uart_start(unsigned int x){
        unsigned int pclk,result;
        if(VPBDIV==0){
                pclk=15000000;
        }else if(VPBDIV==1){
                pclk=60000000;
        }else if(VPBDIV==2){
                pclk=30000000;
        }
        result=pclk/(16*x);
        PINSEL0|=0x05;
        U0LCR=0x83;
        U0DLL=result&0x0ff;
        U0DLM=(result>>8)&0xff;
        U0LCR=0x03;
}
void uart_tx(unsigned char x){
        U0THR=x;
        while((!((U0LSR>>5)&1)));
}
char uart_rx(){
        while((!(U0LSR&1)));
        return U0RBR;
}
void uart_str(char *s){
        while(*s){
                uart_tx(*s++);
        }
}

