#include<iostream>
using namespace std;
int main()
{
	int a,*p;//*p=&a;
	a=1;
	p=&a;//间接获取a的地址
	cout<<*p;
	cout<<endl;
}