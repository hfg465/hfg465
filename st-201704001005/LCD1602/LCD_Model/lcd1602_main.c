#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char

sbit rs=P2^5;             //数据(H)/命令(L)选择端
sbit rw=P2^6;             //读(H)/写(L)端
sbit le=P2^7;             //使能端 H

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
		wr_cmd(0x80);               //第一行地址指针设置
		for(num=0;num<16;num++)
		{
			wr_data(tab1[num]);        //第一行显示16个字符
			delay(500);
		}
		wr_cmd(0x80+0x40);          //第二行地址指针设置
		for(num=0;num<16;num++)
		{
			wr_data(tab2[num]);        //第二行显示字符
			delay(500);	
		}
		wr_cmd(0x80|0x10);            //提前将指针与光标移到 0x80+0x10
		for(num=0;num<7;num++)        // 整屏左移 7 个字符
		{
			wr_cmd(0x18);
			delay(200);
		}
		wr_cmd(0x80+0x10);                //设置第一行显示地址
		for(num=16;num<25;num++)          // 第一行显示后面的数据
		{
			wr_data(tab1[num]);         
			delay(500);
		}
		delay(1000);                //延时大约 1s 后重新开始显示
		wr_cmd(0x0c);               //取消光标
		wr_cmd(0x02);               //指针数据清0
		delay(2000);                //延时大约 2s 
		for(num=0;num<9;num++)
		{
			wr_cmd(0x18);               //整屏左移
			delay(500);
		}                             //右移了以后再左移回来
		for(num=0;num<9;num++)
		{
			wr_cmd(0x1c);               //整屏右移
			delay(500);
		}
		delay(1000);                //延时大约 1s 后重新开始
		wr_cmd(0x0f);               //显示光标并闪烁
		wr_cmd(0x01);               //显示清屏：数据指针清0，所有显示清0
		delay(1000);                //延时大约 1s 后重新开始
	}
}

/*LCD初始化*/
void lcd_init()
{
	le=0;
	wr_cmd(0x38);             //显示模式设置：16×2显示，5×7点阵，8位数据口
	wr_cmd(0x0f);             //开显示，显示光标，光标闪烁；bit2对应显示，bit1对应光标，bit0对应光标闪烁
	wr_cmd(0x06);             //写一个字符后地址指针+1；bit1=1 指针+1，bit1=0 指针-1；bit0=1整屏移动……
	wr_cmd(0x01);             //显示清屏：数据指针清0，所有显示清0  02H：数据指针清0
}

/*液晶状态查询*/
void status()           // status 函数可能出了问题，没有使用
{
	uchar sta;
	P0=0xff;              //读外部状态前 P0 先置高电平
	rs=0;
	rw=1;
	do                //当 P0 有多个中断使用时，读完状态后应置 le=0
	{
		le=1;
		delay(1);
		sta=P0;
	}while(sta&0x80);
	le=0;
}

/*写指令*/
void wr_cmd(uchar cmd)
{
//	status();
	rs=0;
	rw=0;
	le=0;	
	P0=cmd;
	delay(1);             // 稍作延时待数据稳定
	le=1;                 // le 0-1-0,高脉冲
//	delay(1);
	le=0;
}

/*写数据*/
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

/*延时函数*/
void delay(uint xms)
{
	uint i,j;
	for(i=xms;i>0;i--)
		for(j=113;j>0;j--);
}