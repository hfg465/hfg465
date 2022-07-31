#include<iostream>
using namespace std;
int main()
{
	int a,*p;
	a=100;
	p=&a;
	a=*p+100;
	cout<<*p<<endl;
}