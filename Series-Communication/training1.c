#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char

uchar code seg_tab[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,		//����������ܶ���
                   0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x40};
uchar key=16;
sbit seg_ch=P2^0;                //���������Ƭѡ��

void init_main()
{
	EA=1;                   //�ж������� ��
	ES=1;                   //�����ж����� ��
	SM0=0;                  //���ô��й�����ʽ 1
	SM1=1;
	REN=1;                  //�������ݽ������� ��
	TMOD=0x20;              //���ö�ʱ��������ʽ 1
	TH1=0xfd;               //���ö�ʱ��ֵ/�����ʣ�9600 bps
	TL1=0xfd;
	TR1=1;                  //��ʱ������
	seg_ch=0;               //�����Ƭѡ ����
}	
									 
/*���������*/									 
void main()
{
	init_main();
	while(1)
	{
		P0=seg_tab[key];
	}
}

/*����ͨѶ�ж�*/
void touch() interrupt 4
{
	RI=0;	
	key=SBUF;
}