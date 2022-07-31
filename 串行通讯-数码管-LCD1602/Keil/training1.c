#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char

uchar code seg_tab[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,		//共阴极数码管段码
                   0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x40};
uchar code key_to_str[]="0123456789ABCDEF-";  //将键值转换为字符发送
uchar key=16;                    //数码管显示初值设定
sbit seg_ch=P2^0;                //定义数码管片选端
uint i,j;                        //延时函数循环因子
uchar t_key[]="I got a ";        //该芯片收到数据后，返回的内容

void delay(uint xms)
{
	for(i=xms;i>0;i--)
		for(j=113;j>0;j--);
}
									 
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
	uchar i,key0=0;             // key0 用于保存上一个 key 值
	init_main();
	while(1)
	{
		P0=seg_tab[key];
		if(key0!=key)              //若 key 值有变化，发送 t_key[] 与收到的新 key 值
		{
			ES=0;                    //禁止中断，以免发送数据时进入中断程序执行发生混乱
			i=0;
			while(t_key[i]!='\0')    //发送 t_key[]
			{
				SBUF=t_key[i];
				while(!TI);
				TI=0;
				i++;
				delay(5);              //延长两字符间的发送时间间隔，否则发生数据丢失
			}
			key0=key;
			SBUF=key_to_str[key0];   //发送键值
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

/*串行通讯中断*/
void touch() interrupt 4
{
	RI=0;	
	key=SBUF;
}