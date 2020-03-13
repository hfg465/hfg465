#include<stdio.h>
int main()
{
	char c;
	int zm,kg,qt;
	zm=kg=qt=0;
	c=getchar();
	while(c!='\n')
	{
		if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
			zm++;
		else if(c==' ')kg++;
		else qt++;
		c=getchar();
	}
printf("zm=%d,kg=%d,qt=%d\n",zm,kg,qt);
}