#include"head.h"
void adc_start(){
        PINSEL1|= 0x15400000;
        ADCR=0x00200400;
}
int adc_read(unsigned char ch){
        unsigned int data;
        ADCR |=1<<ch;
        ADCR |=1<<24;
        while((!((ADDR>>31)&1)));
        ADCR ^=1<<24;
        ADCR ^=1<<ch;
        data=(ADDR>>6)&0x3FF;
        return data;
}
int adc_val;
float temp_sens(unsigned char ch){
        float vout,temp;
        adc_val=adc_read(ch);
        vout=(adc_val*3.3)/1023.0;
        temp=vout/0.010;
        return temp;
}
float ldr_sens(unsigned char ch){
        float light;
        adc_val=adc_read(ch);
        light=((float)adc_val/1023.0)*100.0;
        light=100.0-light;
        return light;
}
float water_sens(unsigned char ch){
        float water;
        adc_val=adc_read(ch);
        water=((float)adc_val/1023.0)*100.0;
        return water;
}
float soil_sens(unsigned char ch){
        float soil;
        adc_val=adc_read(ch);
 soil=((float)adc_val/1023.0)*100.0;
        soil=100.0-soil;
        if(soil>100.0){
                soil=100.0;
        }else if(soil<0.0){
                soil=0.0;
        }
        return soil;
}

