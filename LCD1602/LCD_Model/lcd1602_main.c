#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char

sbit rs=P2^5;             //����(H)/����(L)ѡ���
sbit rw=P2^6;             //��(H)/д(L)��
sbit le=P2^7;             //ʹ�ܶ� H

uchar num;
uchar code tab1[]="I LOVE MICROCONTROLLER! ";
uchar code tab2[]="I LOVE LEARNING!";

void lcd_init();
void status();
void wr_cmd(uchar);
void wr_data(uchar);
void delay(uint);

void main()
{
	lcd_init();
	while(1)
	{
		wr_cmd(0x80);               //��һ�е�ַָ������
		for(num=0;num<16;num++)
		{
			wr_data(tab1[num]);        //��һ����ʾ16���ַ�
			delay(500);
		}
		wr_cmd(0x80+0x40);          //�ڶ��е�ַָ������
		for(num=0;num<16;num++)
		{
			wr_data(tab2[num]);        //�ڶ�����ʾ�ַ�
			delay(500);	
		}
		wr_cmd(0x80|0x10);            //��ǰ��ָ�������Ƶ� 0x80+0x10
		for(num=0;num<7;num++)        // �������� 7 ���ַ�
		{
			wr_cmd(0x18);
			delay(200);
		}
		wr_cmd(0x80+0x10);                //���õ�һ����ʾ��ַ
		for(num=16;num<25;num++)          // ��һ����ʾ���������
		{
			wr_data(tab1[num]);         
			delay(500);
		}
		delay(1000);                //��ʱ��Լ 1s �����¿�ʼ��ʾ
		wr_cmd(0x0c);               //ȡ�����
		wr_cmd(0x02);               //ָ��������0
		delay(2000);                //��ʱ��Լ 2s 
		for(num=0;num<9;num++)
		{
			wr_cmd(0x18);               //��������
			delay(500);
		}                             //�������Ժ������ƻ���
		for(num=0;num<9;num++)
		{
			wr_cmd(0x1c);               //��������
			delay(500);
		}
		delay(1000);                //��ʱ��Լ 1s �����¿�ʼ
		wr_cmd(0x0f);               //��ʾ��겢��˸
		wr_cmd(0x01);               //��ʾ����������ָ����0��������ʾ��0
		delay(1000);                //��ʱ��Լ 1s �����¿�ʼ
	}
}

/*LCD��ʼ��*/
void lcd_init()
{
	le=0;
	wr_cmd(0x38);             //��ʾģʽ���ã�16��2��ʾ��5��7����8λ���ݿ�
	wr_cmd(0x0f);             //����ʾ����ʾ��꣬�����˸��bit2��Ӧ��ʾ��bit1��Ӧ��꣬bit0��Ӧ�����˸
	wr_cmd(0x06);             //дһ���ַ����ַָ��+1��bit1=1 ָ��+1��bit1=0 ָ��-1��bit0=1�����ƶ�����
	wr_cmd(0x01);             //��ʾ����������ָ����0��������ʾ��0  02H������ָ����0
}

/*Һ��״̬��ѯ*/
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
}

/*дָ��*/
void wr_cmd(uchar cmd)
{
//	status();
	rs=0;
	rw=0;
	le=0;	
	P0=cmd;
	delay(1);             // ������ʱ�������ȶ�
	le=1;                 // le 0-1-0,������
//	delay(1);
	le=0;
}

/*д����*/
void wr_data(uchar dat)
{
//	status();
	rs=1;
	rw=0;
	le=0;
	P0=dat;
	delay(1);
	le=1;
//	delay(1);
	le=0;
}

/*��ʱ����*/
void delay(uint xms)
{
	uint i,j;
	for(i=xms;i>0;i--)
		for(j=113;j>0;j--);
}