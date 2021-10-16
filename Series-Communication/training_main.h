#ifndef TRAINING_MAIN_H
#define TRAINING_MAIN_H
#define uint unsigned int
#define uchar unsigned char
	
sfr seg = 0x90;              // 数码管接上 P1
sbit seg_ch = P2^0;          //数码管位选端，共阴极输出 0 选通
sbit lcd_ce=P2^1;            //LCD 片选端
sbit lcd_cd=P2^2;            //LCD命令/数据选择端，1=C，0=D
sbit lcd_fs=P2^3;            //LCD字体选择端，1=8*6,0=8*8
sbit lcd_rst=P2^4;           //LCD复位端，低电平有效
sbit lcd_wr=P3^6;            //
sbit lcd_rd=P3^7;

uchar key=16;                 //键码
uint i,j;                     //循环因子
uchar code seg_tab[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,		//共阴极数码管段码
                   0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x40};
void delay(uint);
									 
#endif