//LCD_driver_prac.c
#include <LPC21xx.h>
#include "LCD_def_prac.h"
#include "delay.h"
#include "types.h"

void WriteLCD(unsigned char ch){
IOCLR0=1<<LCD_rw;
IOPIN0=((IOPIN0&~(255<<LCD_data)) |(ch<<LCD_data));
IOSET0=1<<LCD_en;
delay_us(1);
IOCLR0=1<<LCD_en;
delay_ms(2);
}
void CmdLCD(unsigned char ch){
IOCLR0=1<<LCD_rs;
WriteLCD(ch);
}
void Init_LCD(){
IODIR0|=(255<<LCD_data)|(1<<LCD_en)|(1<<LCD_rs)|(1<<LCD_rw);
delay_ms(15);
CmdLCD(0x30);
delay_ms(4);
CmdLCD(0x30);
delay_us(100);
CmdLCD(0x30);
CmdLCD(LCD_8BIT_2LINE);
CmdLCD(LCD_DISP_ON_CUR_OFF);
CmdLCD(LCD_CLEAR_DISP);
CmdLCD(LCD_SHIFT_RIGHT);
}
void CharLCD(unsigned char ch){
IOSET0=1<<LCD_rs;
WriteLCD(ch);
}
void StrLCD(char *str){
while(*str){
CharLCD(*str++);

}

}
void U32LCD(u32 num){
int i;
char arr[10];

while(num!=0){
arr[i]=(num%10)+'0';
i++;
}
while(--i>=0){
CharLCD(arr[i]);
}

}

void S32LCD(s32 num){
if(num<0){
CharLCD('-');
}
U32LCD(num);
}
void F32LCD(float num,int ndp){
s32 temp=num;
if(temp<0){
S32LCD(temp);
num=-num;
}
else{
U32LCD(temp);
}
num=num-temp;
CharLCD('.');
while(ndp>=0){
num=num*10;
temp=num;
CharLCD(temp+'0');
num=num-temp;
}
}

//void BuildCGRAM(unsigned char *p,unsigned char nBytes,){

//}
