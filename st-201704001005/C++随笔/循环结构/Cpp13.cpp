/*��������������д������m��n֮�䣨����m��n��m<=n�������ĸ�������ƽ��ֵ�����û��
���������no��m��n�ɼ������롣
������˵�������������ֱ���m��ֵ��n��ֵ
�����˵�������������ֱ�����������������ƽ��ֵ
����������1��1 10 
���������1��4 4.25 
����������2��8 10 
���������2��no
������˵����1��10֮����4�����������ǵ�ƽ��ֵ��4.25��8��10֮��û�����������"no"*/
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