#ifndef TRAINING_MAIN_H
#define TRAINING_MAIN_H
#define uint unsigned int
#define uchar unsigned char
	
sfr seg = 0x90;              // ����ܽ��� P1
sbit seg_ch = P2^0;          //�����λѡ�ˣ���������� 0 ѡͨ
sbit lcd_ce=P2^1;            //LCD Ƭѡ��
sbit lcd_cd=P2^2;            //LCD����/����ѡ��ˣ�1=C��0=D
sbit lcd_fs=P2^3;            //LCD����ѡ��ˣ�1=8*6,0=8*8
sbit lcd_rst=P2^4;           //LCD��λ�ˣ��͵�ƽ��Ч
sbit lcd_wr=P3^6;            //
sbit lcd_rd=P3^7;

uchar key=16;                 //����
uint i,j;                     //ѭ������
uchar code seg_tab[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,		//����������ܶ���
                   0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x40};
void delay(uint);
									 
#endif