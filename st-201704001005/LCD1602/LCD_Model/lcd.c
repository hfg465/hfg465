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

/*****写命令入LCD*****/
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

/*****写数据入LCD******/
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

/*****初始化LCD******/
void init_lcd()
{
	dula=0;
	wela=0;
	lcden=0;
	write_cmd(0x38);	  //设置16*2显示，5*7点阵，8位数据口
	write_cmd(0x0c);	 //设置开显示，不显示光标
	write_cmd(0x06);	  //写一个字符后，地址指针加 1
	write_cmd(0x01);	  //显示清零，数据指针清零
}

/*****设定显示位置*****/
void lcd_position(uchar x,uchar y)
{
	if(x==1)
		write_cmd(0x80+y);		   //数据指针=80+地址变量，80+00
	if(x==2)
		write_cmd(0xc0+y);
	if(x==3)
		write_cmd(0x90+y);		   //  80+10
	if(x==4)
		write_cmd(0xd0+y);
}

/*****显示字符******/
void lcd_string(uchar x,uchar y,uchar str[])
{
	uchar i;
	uint q,w;
	lcd_position(x,y);
	for(i=0;str[i]!='\0';i++)
		write_data(str[i]);
	for(q=5;q>0;q--)		   //延时大约 5ms
		for(w=114;w>0;w--);
}

/*****显示数字*****
void lcd_data(uchar dat)
{

}*/

/*****显示函数*****/
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