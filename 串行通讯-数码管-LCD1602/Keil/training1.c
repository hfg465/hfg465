#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char

uchar code seg_tab[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,		//����������ܶ���
                   0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x40};
uchar code key_to_str[]="0123456789ABCDEF-";  //����ֵת��Ϊ�ַ�����
uchar key=16;                    //�������ʾ��ֵ�趨
sbit seg_ch=P2^0;                //���������Ƭѡ��
uint i,j;                        //��ʱ����ѭ������
uchar t_key[]="I got a ";        //��оƬ�յ����ݺ󣬷��ص�����

void delay(uint xms)
{
	for(i=xms;i>0;i--)
		for(j=113;j>0;j--);
}
									 
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
	uchar i,key0=0;             // key0 ���ڱ�����һ�� key ֵ
	init_main();
	while(1)
	{
		P0=seg_tab[key];
		if(key0!=key)              //�� key ֵ�б仯������ t_key[] ���յ����� key ֵ
		{
			ES=0;                    //��ֹ�жϣ����ⷢ������ʱ�����жϳ���ִ�з�������
			i=0;
			while(t_key[i]!='\0')    //���� t_key[]
			{
				SBUF=t_key[i];
				while(!TI);
				TI=0;
				i++;
				delay(5);              //�ӳ����ַ���ķ���ʱ���������������ݶ�ʧ
			}
			key0=key;
			SBUF=key_to_str[key0];   //���ͼ�ֵ
			while(!TI);
			TI=0;
			delay(5);
			SBUF='.';
			while(!TI);
			TI=0;
			ES=1;
		}
	}
}

/*����ͨѶ�ж�*/
void touch() interrupt 4
{
	RI=0;	
	key=SBUF;
}