#include<iostream>
#include<cmath>
using namespace std;
int hanshu(int x)
{
	int m,i,f=0;
	m=sqrt(x);
	for(i=2;i<=m;i++)
		if(x%i==0)
			break;
		if(i==m+1&&x!=1)f=1;
		if(f==0)return 0;
		else return 1;
}
int main()
{
	int s,a;
	cin>>a;
	s=hanshu(a);
	if(s==0)cout<<a<<",no\n";
	else cout<<a<<",yes\n";
}