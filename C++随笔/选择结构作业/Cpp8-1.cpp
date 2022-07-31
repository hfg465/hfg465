#include<iostream>
using namespace std;
int main()
{
	int i=0;
	char t;
	while(i<5)
	{
		cin>>t;
		t+=4;
		if(t>'z')t-=26;
		cout<<t;
		i++;
	}
	cout<<"\n";
}