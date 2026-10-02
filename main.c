#include"head.h"
#define LDR (!((IOPIN0>>10)&1))
#define LED 7<<17
int main(){
        float soil,temp,water,ldr;
        int x=0;
        char t[30],s[30],s1[30],w[30],l[30],t1[30],lcd[20];
        IODIR0|=LED;
        adc_start();
        uart_start(9600);
        lcd_start();
        while(1){
                x=0;
                lcd_start();
                IOSET0=LED;
                temp=temp_sens(0);
                water=water_sens(1);
                soil=soil_sens(2);
                ldr=ldr_sens(3);
                if(water>40.0){
                                sprintf(w,"WATER      :DETECTED\r\n",water);
                                lcd_str("WATE",2);
                }else{
                                lcd_str("NWAT",2);
                                sprintf(w,"WATER      :NOT DETECTED\r\n",water);
                }
                                sprintf(t,"TEMP       :%.2f%\r\n",temp);
                if(temp<41.0){
                                sprintf(t1,"TEMP       :SAFE\r\n");
                }else{
                                sprintf(t1,"TEMP       :HOT\r\n");
                }
                                sprintf(s,"SOIL       :%.2f%\r\n",soil);
                                sprintf(lcd,"Soil_%.2f",soil);
                                lcd_str(lcd,1);
                if(soil<50){
                                sprintf(s1,"SOIL       :NEED WATER\r\n");
                }else{
                                sprintf(s1,"SOIL       :NO NEED WATER\r\n");
 }
                if(LDR>45.0){
                        if(ldr<75.0){
                            sprintf(l,"LIGHT      :MIDLEVEL\r\n",ldr);
                                lcd_str("MID",3);
                          }else{
                                sprintf(l,"LIGHT      :HIGH\r\n",ldr);
                                lcd_str("HIG",3);
                        }
                }else{
                                sprintf(l,"LIGHT      :Normal\r\n",ldr);
                                lcd_str("LOW",3);
                }
                if(temp>40){
                        x=1;
                }
                if(water>40.0){
                        if(water>75.0){
                                x=1;
                        }
                        if(!x){
                                x=2;
                        }
                }
                if(soil>40.0){
                        if(soil>75.0){
                                x=1;
                        }
                        if(!x){
                                x=2;
                        }
                }
                if(ldr>40.0){
                        if(ldr>75.0){
                                x=1;
                        }
                        if(!x){
                                x=2;
                        }
 }
                uart_str(t);
                uart_str(t1);
                uart_str(w);
                uart_str(s);
                uart_str(s1);
                uart_str(l);
                sprintf(lcd,"%.2f",temp);
                lcd_str(lcd,0);
                if(x==1){
                        uart_str("Final   :Danger\r\n");
                        lcd_str("Danger",4);
                        IOCLR0=1<<19;
                }else if(x==2){
                        lcd_str("Warnig",4);
                        uart_str("Final   :Warnig\r\n");
                        IOSET0=1<<18;
                }else{
                        IOSET0=1<<17;
                        uart_str("Final   :Safe\r\n");
                        lcd_str("Safe",4);
                }
                delay_ms(100);
        }
}

