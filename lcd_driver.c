#include"head.h"
#define BIT 0xFE
#define IODIR IODIR1
#define IOCLR IOCLR1
#define IOSET IOSET1
#define RS 1<<17
#define RW 1<<18
#define EN 1<<19
void com_1(unsigned char x,int a){
        IOCLR=BIT<<16;
        if(a){
                IOSET=x<<16;
        }else{
                IOSET=x<<20;
        }
}
void com_2(){
        IOCLR=RW;
        IOSET=EN;
        delay_ms(2);
        IOCLR=EN;
}
void lcd_data(unsigned char x){
        com_1(x&0xf0,1);
        IOSET= RS;
        com_2();
        com_1(x&0xf,0);
        IOSET=RS;
        com_2();
}
void lcd_cmd(unsigned char x){
        com_1(x&0xf0,1);
        IOCLR= RS;
        com_2();
        com_1(x&0xf,0);
        IOCLR=RS;
        com_2();
}
void lcd_start(){
	IODIR=BIT<<16;
        lcd_cmd(0x02);
        lcd_cmd(0x28);
        lcd_cmd(0x01);
        lcd_cmd(0xe);
}
void lcd_str(char *s,int x){
        int i;
        if(x==0){
                i=0x80;
                for(;i<=0x84 && *s;i++){
                        lcd_cmd(i);
                        lcd_data(*s++);
                }
        }else if(x==1){
                i=0x86;
                for(;i<=0x8F && *s;i++){
                        lcd_cmd(i);
                        lcd_data(*s++);
                }
        }else if(x==2){
                 i=0xc0;
                 for(;i<=0xc3 && *s;i++){
                        lcd_cmd(i);
                        lcd_data(*s++);
                 }
        }else if(x==3){
                 i=0xc5;
                 for(;i<=0xc7 && *s;i++){
                        lcd_cmd(i);
                        lcd_data(*s++);
                 }
        }else if(x==4){
                i=0xc9;
                for(;i<=0xcF && *s;i++){
                        lcd_cmd(i);
                        lcd_data(*s++);
                }
        }
}
