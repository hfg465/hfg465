#ifndef LCD_1602_H
#define LCD_1602_H

#define uint unsigned int
#define uchar unsigned char

sbit rs=P3^7;             //����(H)/����(L)ѡ���
sbit rw=P3^6;             //��(H)/д(L)��
sbit le=P3^5;             //ʹ�ܶ� H

//uint i,j;                     //ѭ������
//uchar num;

void lcd_init();
void status();
void wr_cmd(uchar);
void wr_data(uchar);
void delay(uint);
//void lcd_1602();

#endif