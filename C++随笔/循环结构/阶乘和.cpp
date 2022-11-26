#include<iostream>
using namespace std;
int main()
{
	int i,k,n;
	float y,p;
	y=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		p=1;
		for(k=1;k<=i;k++)
			p*=k;
		y+=p;
	}
	cout<<y<<endl;
}