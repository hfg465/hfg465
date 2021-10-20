#include<reg52.h>
#include<intrins.h>
#include"training_main.h"
#include"lcd_1602.h"

/*单片机初始化*/
void init_51c()
{
	EA=1;                   //中断允许总 开
	ES=1;                   //串行中断允许 开
	EX0=1;                  //外部中断0允许
	TMOD=0x20;              //设定 定时器1 的工作方式 1
	SM0=0;
	SM1=1;                  //串行口工作方式 1
	REN=1;                  //允许串行口接收数据
	TH1=0xfd;
	TL1=0xfd;               //设定初值，波特率为 9600 bps
	TR1=1;                  //启动定时器
	seg_ch=0;               //数码管片选端选择开
	seg=seg_tab[key];       //数码管显示初始化
	IT0=0;                  //外部中断0低电平触发
	P0=0xf0;	              //矩阵键盘低四位送低电平
}

/*主函数入口*/
void main()
{
	uchar key0=0;      //用于判断键值是否更新，若发生更新再发送新的键值，若没有更新则不发送
	init_51c();
	lcd_init();
	while(1)
	{
		seg=seg_tab[key];            //数码管显示键值
		if(key0!=key)
		{
			ES=0;
			SBUF=key;                    //发送键值
			while(!TI);                  //等待发送完成
			TI=0;
			ES=1;
			key0=key;
		}
		if(flag==1)
		{
			ES=0;
			wr_data(aa);
			if(aa=='.')wr_cmd(0x02);       //LCD指针数据清零
			flag=0;
			ES=1;
		}
	}
}

/* INT0 中断 */
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
			while(ret!=0xf0)               //等待按键释放
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
			while(ret!=0xf0)               //等待按键释放
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
			while(ret!=0xf0)               //等待按键释放
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
			while(ret!=0xf0)               //等待按键释放
			{
				P0=0xf7;
				ret=P0&0xf0;
			}
		}		
	}
	P0=0xf0;
}

/*串行口接收中断*/
void rec() interrupt 4
{
	RI=0;
	aa=SBUF;
	flag=1;
}

/* ms延时函数 */
/*
void delay(uint x_ms)
{
	for(i=x_ms;i>0;i--)
		for(j=113;j>0;j--);
}
*/