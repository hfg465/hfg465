#include<iostream>
using namespace std;
int main()
{
	int x,y;
	cin>>x;
	if(x<0)y=x;
	else if(x>=0&&x<10)y=x-1;
	else y=x+1;
	cout<<y<<endl;
}