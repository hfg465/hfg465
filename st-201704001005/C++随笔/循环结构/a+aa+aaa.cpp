#include<iostream>
using namespace std;
int main()
{
	int i,n,a;
	float y,t;
	cin>>n>>a;
	t=0;y=0;
	for(i=0;i<n;i++)
	{
		t=t*10+a;
	    y+=t;
	}
	cout<<y<<endl;
}