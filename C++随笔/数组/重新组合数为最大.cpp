//重新组合数为最大
#include<iostream>
using namespace std;
int main()
{
	int n,i,t,p,r,s,a[50];
	r=0;
	cin>>n;
	while(n!=0)
	{
		a[r]=n%10;
		n/=10;
		r++;
	}
	for(i=0;i<r-1;i++)
		for(t=i+1;t<r;t++)
			if(a[i]<a[t])
			{
				p=a[i];a[i]=a[t];a[t]=p;
			}
			s=0;
			for(i=0;i<r;i++)
				s=s*10+a[i];
			cout<<s<<endl;
}