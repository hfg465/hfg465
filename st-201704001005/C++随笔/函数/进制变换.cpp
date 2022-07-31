#include<iostream>
using namespace std;
int fun(int n,int a[])
{
	int i=0;
	while(n!=0)
	{
		a[i]=n%8;
		n/=8;
		i++;
	}
	return i;
}
int main()
{
	int a[50],n,k,i;
	cin>>n;
	k=fun(n,a);
	for(i=k-1;i>=0;i--)
		cout<<a[i]<<endl;
}