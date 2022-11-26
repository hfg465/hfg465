#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,i,k,a[50],t,m,p,s,b[50],f=0;
	m=s=0;
	cout<<"请输入个数n:  ";
	cin>>n;
	cout<<"请随机输入一组数据:  ";
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
	{
		t=sqrt(a[i]);
		for(k=2;k<=t;k++)
			if(a[i]%k==0)break;
			if(k==t+1&&a[i]!=1)
			{
				f=1;
				b[m]=a[i];
				m++;
			}
	}
	for(i=0;i<m;i++)
		s+=b[i];
	if(f==1)
	cout<<s<<endl<<"素数个数为："<<m<<endl;
	for(i=0;i<m-1;i++)
		for(k=i+1;k<m;k++)
			if(b[i]<b[k])
			{
				p=b[i];b[i]=b[k];b[k]=p;
			}
			for(i=0;i<m;i++)
				cout<<b[i]<<" ";
			cout<<endl;
}