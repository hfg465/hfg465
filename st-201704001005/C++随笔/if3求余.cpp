#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int x,a;
	cin>>x;
	a=x%3;
	if(a==0)
		cout<<pow(x,3)<<",yes\n";
	else
		cout<<pow(x,2)<<",no\n";
	return 0;
}