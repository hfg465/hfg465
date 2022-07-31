#ifndef TRAINING_MAIN_H
#define TRAINING_MAIN_H
#define uint unsigned int
#define uchar unsigned char
	
sfr seg = 0x90;              // 数码管接上 P1
sbit seg_ch = P3^4;          //数码管位选端，共阴极输出 0 选通

uchar key=16;                 //键码
uchar aa;                     //保存接收到的字符
bit flag=0;                   //串行口接收中断触发标志位
////uint i,j;                     //循环因子
uchar code seg_tab[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,		//共阴极数码管段码
                   0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x40};
uchar code pipi[]={'O','K','K','!','!'};
									 extern void delay(uint);
									 
#endif