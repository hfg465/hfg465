#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char
#include<intrins.h>
void display(uchar table[])
{
 uchar m;
 uint i,j;
 for(m=0;m<10;m++)
 {
  P0=table[m];
  for(i=0;i<1000;i++)
     for(j=0;j<110;j++);}
}
void main()
{
 void delay(uint); 
 uchar table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
 display(table);
 P0=0xff;
 while(1)
 {uint i;
 uchar cc,aa=0xfe,bb=0x7f;
 cc=aa;
 for(i=0;i<8;i++)
 {P1=aa;
 delay(500);
 aa=_crol_(aa,1);}
 P1=0x00;
 delay(1000);
 P1=0xff;
 delay(1000);
 P1=0xaa;
 delay(1000);
 P1=0x55;
 delay(1000);
 for(i=0;i<8;i++)
 {P1=bb;
 delay(1000);
 bb=bb>>1;}
 for(i=0;i<8;i++)
 {P1=cc;
 delay(500);
 cc=cc<<1;}
 for(i=0;i<3;i++)
 {P1=0x00;
 delay(300);
 P1=0xff;
 delay(300);
 P1=0xf0;
 delay(300);
 P1=0x0f;
 delay(300);}
 }
}
void delay(uint xms)
{
 uint i,j;
 for(i=xms;i>0;i--)
    for(j=110;j>0;j--);
}