//斐波那契数列求和
#include<iostream>
using namespace std;
int main()
{
	int n,i,f[50]={1,1},s;
	s=0;
	cin>>n;
	for(i=2;i<n;i++)
		f[i]=f[i-1]+f[i-2];
	for(i=0;i<n;i++)
		s+=f[i];
	cout<<s<<endl;
}