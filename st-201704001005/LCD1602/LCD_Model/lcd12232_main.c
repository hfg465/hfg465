#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char

sbit cs=P2^0;             //���п�Ƭѡ�� ѡ�� 1����ѡ 0
sbit sclc=P2^1;           //ʱ�Ӷ�
sbit sid=P2^2;            //���������

//uchar num;
uchar code tab1[]="I LOVE MICROCONTROLLER! ";
uchar code tab2[]="�Ұ���Ƭ��!";

void lcd_init();
void status();
void wr_cmd(uchar);
void wr_data(uchar);
void delay(uint);
void disp_s();
void disp_x();

void main()
{
	lcd_init();
	disp_s();
	disp_x();
	while(1);
}

/*LCD��ʼ��*/
void lcd_init()
{
	delay(100);
	wr_cmd(0x30);             //��ʾģʽ���ã�16��2��ʾ��5��7����8λ���ݿ�
	wr_cmd(0x02);             //����ʾ����ʾ��꣬�����˸��bit2��Ӧ��ʾ��bit1��Ӧ��꣬bit0��Ӧ�����˸
	wr_cmd(0x06);             //дһ���ַ����ַָ��+1��bit1=1 ָ��+1��bit1=0 ָ��-1��bit0=1�����ƶ�����
	wr_cmd(0x0c);             //��ʾ����������ָ����0��������ʾ��0  02H������ָ����0
	wr_cmd(0x01);
	wr_cmd(0x80);
}

/*Һ��״̬��ѯ*/    /*
void status()           // status �������ܳ������⣬û��ʹ��
{
	uchar sta;
	P0=0xff;              //���ⲿ״̬ǰ P0 ���øߵ�ƽ
	rs=0;
	rw=1;
	do                //�� P0 �ж���ж�ʹ��ʱ������״̬��Ӧ�� le=0
	{
		le=1;
		delay(1);
		sta=P0;
	}while(sta&0x80);
	le=0;
}*/

/*дָ��*/
void wr_cmd(uchar cmd)
{
	uchar i,i_dat;
	i_dat=0xf8;            // дָ���ָ����
	cs=1;
	sclc=0;	
	for(i=0;i<8;i++)
	{
		sid=(bit)i_dat&0x80;
		sclc=0;
		sclc=1;
		i_dat<<=1;
	}
	i_dat=cmd;
	i_dat&=0xf0;
	for(i=0;i<8;i++)
	{
		sid=(bit)i_dat&0x80;
		sclc=0;
		sclc=1;
		i_dat<<=1;
	}
	i_dat=cmd;
	i_dat<<=4;
	for(i=0;i<8;i++)
	{
		sid=(bit)i_dat&0x80;
		sclc=0;
		sclc=1;
		i_dat<<=1;
	}
	cs=0;
	delay(1);
}

/*д����*/
void wr_data(uchar dat)
{
	uchar i,i_dat;
	i_dat=0xfa;            // д���ݵ�ָ����
	cs=1;
	sclc=0;	
	for(i=0;i<8;i++)
	{
		sid=(bit)i_dat&0x80;
		sclc=0;
		sclc=1;
		i_dat<<=1;
	}
	i_dat=dat;
	i_dat&=0xf0;
	for(i=0;i<8;i++)
	{
		sid=(bit)i_dat&0x80;
		sclc=0;
		sclc=1;
		i_dat<<=1;
	}
	i_dat=dat;
	i_dat<<=4;
	for(i=0;i<8;i++)
	{
		sid=(bit)i_dat&0x80;
		sclc=0;
		sclc=1;
		i_dat<<=1;
	}
	cs=0;
	delay(1);
}

/*��ʾ��һ���ַ�*/
void disp_s()
{
	uchar a;
	wr_cmd(0x80);
	for(a=0;a<25;a++)
	{
		wr_data(tab1[a]);
	}
}

void disp_x()
{
	uchar b;
	wr_cmd(0x90);
	for(b=0;b<11;b++)
	{
		wr_data(tab2[b]);
	}
}

/*��ʱ����*/
void delay(uint xms)
{
	uint i,j;
	for(i=xms;i>0;i--)
		for(j=113;j>0;j--);
}