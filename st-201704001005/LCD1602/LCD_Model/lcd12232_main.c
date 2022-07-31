#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char

sbit cs=P2^0;             //串行口片选端 选中 1；不选 0
sbit sclc=P2^1;           //时钟端
sbit sid=P2^2;            //数据输入端

//uchar num;
uchar code tab1[]="I LOVE MICROCONTROLLER! ";
uchar code tab2[]="我爱单片机!";

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

/*LCD初始化*/
void lcd_init()
{
	delay(100);
	wr_cmd(0x30);             //显示模式设置：16×2显示，5×7点阵，8位数据口
	wr_cmd(0x02);             //开显示，显示光标，光标闪烁；bit2对应显示，bit1对应光标，bit0对应光标闪烁
	wr_cmd(0x06);             //写一个字符后地址指针+1；bit1=1 指针+1，bit1=0 指针-1；bit0=1整屏移动……
	wr_cmd(0x0c);             //显示清屏：数据指针清0，所有显示清0  02H：数据指针清0
	wr_cmd(0x01);
	wr_cmd(0x80);
}

/*液晶状态查询*/    /*
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
}*/

/*写指令*/
void wr_cmd(uchar cmd)
{
	uchar i,i_dat;
	i_dat=0xf8;            // 写指令的指令码
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

/*写数据*/
void wr_data(uchar dat)
{
	uchar i,i_dat;
	i_dat=0xfa;            // 写数据的指令码
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

/*显示第一行字符*/
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

/*延时函数*/
void delay(uint xms)
{
	uint i,j;
	for(i=xms;i>0;i--)
		for(j=113;j>0;j--);
}