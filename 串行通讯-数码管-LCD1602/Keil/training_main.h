#ifndef TRAINING_MAIN_H
#define TRAINING_MAIN_H
#define uint unsigned int
#define uchar unsigned char
	
sfr seg = 0x90;              // ����ܽ��� P1
sbit seg_ch = P3^4;          //�����λѡ�ˣ���������� 0 ѡͨ

uchar key=16;                 //����
uchar aa;                     //������յ����ַ�
bit flag=0;                   //���пڽ����жϴ�����־λ
////uint i,j;                     //ѭ������
uchar code seg_tab[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,		//����������ܶ���
                   0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x40};
uchar code pipi[]={'O','K','K','!','!'};
									 extern void delay(uint);
									 
#endif