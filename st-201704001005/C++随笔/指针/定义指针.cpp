#include<iostream>
using namespace std;
int main()
{
	int a,*p;//*p=&a;
	a=1;
	p=&a;//��ӻ�ȡa�ĵ�ַ
	cout<<*p;
	cout<<endl;
}