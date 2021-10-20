#include<reg52.h>
#include<intrins.h>
#include"training_main.h"
#include"lcd_1602.h"

/*��Ƭ����ʼ��*/
void init_51c()
{
	EA=1;                   //�ж������� ��
	ES=1;                   //�����ж����� ��
	EX0=1;                  //�ⲿ�ж�0����
	TMOD=0x20;              //�趨 ��ʱ��1 �Ĺ�����ʽ 1
	SM0=0;
	SM1=1;                  //���пڹ�����ʽ 1
	REN=1;                  //�����пڽ�������
	TH1=0xfd;
	TL1=0xfd;               //�趨��ֵ��������Ϊ 9600 bps
	TR1=1;                  //������ʱ��
	seg_ch=0;               //�����Ƭѡ��ѡ��
	seg=seg_tab[key];       //�������ʾ��ʼ��
	IT0=0;                  //�ⲿ�ж�0�͵�ƽ����
	P0=0xf0;	              //������̵���λ�͵͵�ƽ
}

/*���������*/
void main()
{
	uchar key0=0;      //�����жϼ�ֵ�Ƿ���£������������ٷ����µļ�ֵ����û�и����򲻷���
	init_51c();
	lcd_init();
	while(1)
	{
		seg=seg_tab[key];            //�������ʾ��ֵ
		if(key0!=key)
		{
			ES=0;
			SBUF=key;                    //���ͼ�ֵ
			while(!TI);                  //�ȴ��������
			TI=0;
			ES=1;
			key0=key;
		}
		if(flag==1)
		{
			ES=0;
			wr_data(aa);
			if(aa=='.')wr_cmd(0x02);       //LCDָ����������
			flag=0;
			ES=1;
		}
	}
}

/* INT0 �ж� */
void m_kb() interrupt 0
{
	uchar ret;
	delay(8);
	if(P0!=0xf0)
	{
		P0=0xfe;                      // 1
		ret=P0&0xf0;
		if(ret!=0xf0)
		{
			switch(ret)
			{
				case 0xe0:key=0;break;
				case 0xd0:key=1;break;
				case 0xb0:key=2;break;
				case 0x70:key=3;break;
				default:key=16;
			}
			while(ret!=0xf0)               //�ȴ������ͷ�
			{
				P0=0xfe;
				ret=P0&0xf0;
			}
		}
		P0=0xfd;                      // 2
		ret=P0&0xf0;
		if(ret!=0xf0)
		{
			switch(ret)
			{
				case 0xe0:key=4;break;
				case 0xd0:key=5;break;
				case 0xb0:key=6;break;
				case 0x70:key=7;break;
				default:key=16;
			}
			while(ret!=0xf0)               //�ȴ������ͷ�
			{
				P0=0xfd;
				ret=P0&0xf0;
			}
		}
		P0=0xfb;                      // 3
		ret=P0&0xf0;
		if(ret!=0xf0)
		{
			switch(ret)
			{
				case 0xe0:key=8;break;
				case 0xd0:key=9;break;
				case 0xb0:key=10;break;
				case 0x70:key=11;break;
				default:key=16;
			}
			while(ret!=0xf0)               //�ȴ������ͷ�
			{
				P0=0xfb;
				ret=P0&0xf0;
			}
		}
		P0=0xf7;                      // 4
		ret=P0&0xf0;
		if(ret!=0xf0)
		{
			switch(ret)
			{
				case 0xe0:key=12;break;
				case 0xd0:key=13;break;
				case 0xb0:key=14;break;
				case 0x70:key=15;break;
				default:key=16;
			}
			while(ret!=0xf0)               //�ȴ������ͷ�
			{
				P0=0xf7;
				ret=P0&0xf0;
			}
		}		
	}
	P0=0xf0;
}

/*���пڽ����ж�*/
void rec() interrupt 4
{
	RI=0;
	aa=SBUF;
	flag=1;
}

/* ms��ʱ���� */
/*
void delay(uint x_ms)
{
	for(i=x_ms;i>0;i--)
		for(j=113;j>0;j--);
}
*/