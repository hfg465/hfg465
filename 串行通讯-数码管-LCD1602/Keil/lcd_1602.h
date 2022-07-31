#ifndef LCD_1602_H
#define LCD_1602_H

#define uint unsigned int
#define uchar unsigned char

sbit rs=P3^7;             //数据(H)/命令(L)选择端
sbit rw=P3^6;             //读(H)/写(L)端
sbit le=P3^5;             //使能端 H

//uint i,j;                     //循环因子
//uchar num;

void lcd_init();
void status();
void wr_cmd(uchar);
void wr_data(uchar);
void delay(uint);
//void lcd_1602();

#endif