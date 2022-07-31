#include<stdio.h>
#include<math.h>
main()
{
	int i,n,f,k,w;
	n=0;
	for(i=1;i<=100;i++)
	{
		f=0;
		for(k=1;k<i;k++)
		  if(i%k==0)f++;
		if(f==1&&i!=1)
		{
			printf("%d",i);
			n++;
			printf(" ");
		}
		if(n!=0&&n%5==0)printf("\n");
	}
}