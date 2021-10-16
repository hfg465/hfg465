#ifndef LCD_H
#define LCD_H
#define uint unsigned int
#define uchar unsigned char

/****端口定义*****/
sbit csb=P2^0;
sbit scl=P2^2;
sbit warn=P2^1;
sbit sda=P2^3;
sbit ds18=P2^4;
sbit wela=P2^5;
sbit dula=P2^6;
sbit lcden=P2^7;
sbit rs=P3^6;
sbit rw=P3^7;

/*****微妙级延时函数*****/
 void delay_us(uchar);

/******延时函数******/
 void delay_ms(uint);

/*****检测设备是否忙******/
bit lcd_busy();

/*****写命令入LCD*****/
void write_cmd(uchar);

/*****写数据入LCD******/
void write_data(uchar);

/*****初始化LCD******/
void init_lcd();

/*****设定显示位置*****/
void lcd_position(uchar,uchar);

/*****显示字符******/
void lcd_string(uchar,uchar,uchar);

/*****显示函数*****/
void lcd_display(uchar);