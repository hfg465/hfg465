/*【问题描述】已知 ，计算S的值，直到某一项的绝对值小于e为止（小于e的这项不累加），e由
键盘输入。
【输入形式】e的值
【输出形式】S的值
【样例输入】1E-4
【样例输出】0.866924*/
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int m,t,i=1;
	float p,n,s=0;
	cin>>n;
	m=1;p=1;
	while(fabs(p)>=n)
	{
		s+=p;
		m=-m;
		i+=4;
		p=m*1.0/i;
	}
	cout<<s<<endl;
}