#include<reg52.h>
#include<intrins.h>
#include"lcd0.h"

uchar temp[]="temp:";
uchar unit_temp[]={"C"};
uchar wspeed[]={"speed:"};
uchar unit_wspeed[]={"m/s"};
uchar area[]={"area:"};
uchar unit_area[]={"m2"};
uchar wcap[]={"cap:"};
uchar unit_wcap[]={"m3/s"};

void main()
{
	uint i;
	init_lcd();
	for(i=1;i<=4;i++)
		lcd_display(i);
	while(1);
}

/*****д������LCD*****/
void write_cmd(uchar cmd)
{
	rs=0;
	rw=0;
	P0=cmd;
	delay_ms(5);
	lcden=1;
	delay_ms(5);
	lcden=0;
}

/*****д������LCD******/
void write_data(uchar dat)
{
	rs=1;
	rw=0;
	P0=dat;
	delay_ms(5);
	lcden=1;
	delay_ms(5);
	lcden=0;
}

/*****��ʼ��LCD******/
void init_lcd()
{
	dula=0;
	wela=0;
	lcden=0;
	write_cmd(0x38);	  //����16*2��ʾ��5*7����8λ���ݿ�
	write_cmd(0x0c);	 //���ÿ���ʾ������ʾ���
	write_cmd(0x06);	  //дһ���ַ��󣬵�ַָ��� 1
	write_cmd(0x01);	  //��ʾ���㣬����ָ������
}

/*****�趨��ʾλ��*****/
void lcd_position(uchar x,uchar y)
{
	if(x==1)
		write_cmd(0x80+y);		   //����ָ��=80+��ַ������80+00
	if(x==2)
		write_cmd(0xc0+y);
	if(x==3)
		write_cmd(0x90+y);		   //  80+10
	if(x==4)
		write_cmd(0xd0+y);
}

/*****��ʾ�ַ�******/
void lcd_string(uchar x,uchar y,uchar str[])
{
	uchar i;
	uint q,w;
	lcd_position(x,y);
	for(i=0;str[i]!='\0';i++)
		write_data(str[i]);
	for(q=5;q>0;q--)		   //��ʱ��Լ 5ms
		for(w=114;w>0;w--);
}

/*****��ʾ����*****
void lcd_data(uchar dat)
{

}*/

/*****��ʾ����*****/
void lcd_display(uchar var)
{
	switch(var)
	{
		case 1:	lcd_string(1,0,temp);lcd_string(1,13,unit_temp);break;
		case 2: lcd_string(2,0,wspeed);lcd_string(2,12,unit_wspeed);break;
		case 3: lcd_string(3,0,area);lcd_string(3,12,unit_area);break;
		case 4: lcd_string(4,0,wcap);lcd_string(4,11,unit_wcap);break;
	}
}
void delay_ms(uint x)
{
	
	uint i,j;
	for(i=x;i>0;i--)
		for(j=114;j>0;j--);
}
void delay_us(uchar y)
{
	uchar i;
	for(i=0;i<y;i++)
		_nop_();
}