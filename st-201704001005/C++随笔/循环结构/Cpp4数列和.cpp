/*【问题描述】有一分数序列 ，计算该序列的前n项和，n由键盘输入。
【样例输入】20
【样例输出】32.6603
【样例说明】该数列前20项之和为32.6603*/
#include<iostream>
using namespace std;
int main()
{
	int a,b,c,i,n;
	float s=0;
	cin>>n;
	a=1;b=2;
	for(i=1;i<=n;i++)
	{
		s+=1.0*b/a;
		c=b;
		b=a+b;
		a=c;
	}
	cout<<s<<endl;
}