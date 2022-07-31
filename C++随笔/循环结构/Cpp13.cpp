/*【问题描述】编写程序求m到n之间（包括m和n，m<=n）素数的个数及其平均值，如果没有
素数则输出no，m和n由键盘输入。
【输入说明】两个数，分别是m的值和n的值
【输出说明】两个数，分别是素数个数和素数平均值
【样例输入1】1 10 
【样例输出1】4 4.25 
【样例输入2】8 10 
【样例输出2】no
【样例说明】1到10之间有4个素数，它们的平均值是4.25；8到10之间没有素数，输出"no"*/
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int m,n,i,j,t,k,s;
	s=0;t=0;
	cin>>m>>n;
	for(i=m;i<=n;i++)
	{
		k=sqrt(i);
		for(j=2;j<=k;j++)
			if(i%j==0)break;
		if(j==k+1&&i!=1)
			{
				s+=i;t++;
			}
	}
	if(t==0)
		cout<<"no\n";
    else 
		cout<<t<<" "<<s*1.0/t<<endl;
}/*
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int i,j,m,n,gs,s,k;
	gs=0;s=0;
	cin>>m>>n;
	for(i=m;i<=n;i++)
	{
		k=sqrt(i);
		for(j=2;j<=k;j++)
			if(i%j==0)break;
		if(j==k+1&&i!=1)
		{
			s+=i;
			gs++;
		}
	}
	if(gs==0)
		cout<<"no";
	else
		cout<<gs<<" "<<s*1.0/gs;
}*/