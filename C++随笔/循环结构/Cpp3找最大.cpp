/*【问题描述】编写程序找出一个正整数n的各位数字中最大的数字，n由键盘输入。
【样例输入】1423
【样例输出】4
【样例说明】1423有4位数字，分别是1、4、2、3，其中最大值是4*/
#include<iostream>
using namespace std;
int main()
{
	int n,i,m=0;
	cin>>n;
	while(n!=0)
	{
		i=n%10;
		if(m<i)m=i;
		n/=10;
	}
	cout<<m<<"\n";
}
