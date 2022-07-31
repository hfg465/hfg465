#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char

uchar code seg_tab[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,		//共阴极数码管段码
                   0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x40};
uchar key=16;
sbit seg_ch=P2^0;                //定义数码管片选端

void init_main()
{
	EA=1;                   //中断总允许 开
	ES=1;                   //串行中断允许 开
	SM0=0;                  //设置串行工作方式 1
	SM1=1;
	REN=1;                  //串行数据接收允许 开
	TMOD=0x20;              //设置定时器工作方式 1
	TH1=0xfd;               //设置定时初值/波特率，9600 bps
	TL1=0xfd;
	TR1=1;                  //定时器开启
	seg_ch=0;               //数码管片选 开启
}	
									 
/*主函数入口*/									 
void main()
{
	init_main();
	while(1)
	{
		P0=seg_tab[key];
	}
}

/*串行通讯中断*/
void touch() interrupt 4
{
	RI=0;	
	key=SBUF;
}