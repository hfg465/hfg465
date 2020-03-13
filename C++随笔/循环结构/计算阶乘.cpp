#include<iostream>
using namespace std;
int main()
{
	int i,n;
	float y;
	y=1;
	cin>>n;
	for(i=1;i<=n;i++)
		y*=i;
	cout<<"y="<<y<<"\n";
}