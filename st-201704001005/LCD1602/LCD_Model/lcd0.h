#ifndef LCD_H
#define LCD_H
#define uint unsigned int
#define uchar unsigned char

/****�˿ڶ���*****/
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

/*****΢���ʱ����*****/
 void delay_us(uchar);

/******��ʱ����******/
 void delay_ms(uint);

/*****����豸�Ƿ�æ******/
bit lcd_busy();

/*****д������LCD*****/
void write_cmd(uchar);

/*****д������LCD******/
void write_data(uchar);

/*****��ʼ��LCD******/
void init_lcd();

/*****�趨��ʾλ��*****/
void lcd_position(uchar,uchar);

/*****��ʾ�ַ�******/
void lcd_string(uchar,uchar,uchar);

/*****��ʾ����*****/
void lcd_display(uchar);