/*问题描述】输入两个正整数a和b，求出其最大公约数和最小公倍数并输出。
【输入文件】从标准输入读取一行，是两个整数a和b，以空格分隔。
【输出文件】向标准输出打印以空格分隔的两个整数，分别是a、b的最大公约数和最小公倍数。
【输入样例】12 18
【输出样例】6 36
【样例说明】12和18的最大公约数是6，最小公倍数是36.*/
#include<iostream>
using namespace std;
int main()
{
	int a,b,r,a1,b1;
	cin>>a>>b;
	a1=a;b1=b;
	if(a>b)r=a%b;
	else r=b%a;
	while(r!=0)
	{
		if(a>b)
		{
			a=b;b=r;r=a%b;
		}
		else
		{
			b=a;a=r;r=b%a;
		}
	}
	if(a>b)cout<<b<<"  "<<a1*b1/b<<endl;
	else cout<<a<<"  "<<a1*b1/a<<endl;
}