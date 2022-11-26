#include<iostream>
using namespace std;
int main()
{
	int i,n;
	float p,y;
	cin>>n;
	p=1;y=0;
	for(i=1;i<=n;i++)
	{
		p*=i;y+=p;
	}
	cout<<y<<endl;
}