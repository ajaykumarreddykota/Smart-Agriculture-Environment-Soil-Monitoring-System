#include<lpc21xx.h>
#include<stdio.h>
extern void uart_start(unsigned int);
extern void uart_tx(unsigned char);
extern char uart_rx(void);
extern void delay_ms(unsigned int);
extern void adc_start(void);
extern int ac_read(unsigned char);
extern void lcd_start(void);
extern void com_1(unsigned char,int);
extern void com_2(void);
extern void lcd_cmd(unsigned char);
extern void lcd_data(unsigned char);
extern float temp_sens(unsigned char);
extern float soil_sens(unsigned char);
extern float water_sens(unsigned char);
extern float ldr_sens(unsigned char);
extern void uart_str(char *s);
extern void lcd_str(char *s,int);

