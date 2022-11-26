/*【问题描述】求1~N的阶乘之和S， ，N由键盘输入，注意： 。
【输入形式】一个正整数   
【输出形式】一个实型数据
【样例输入】10
【样例输出】4.03791e+006 
【样例说明】10的阶乘值很大，输出时计算机自动以指数形式输出，4.03791e+006 
表示4.03791×106*/
#include<iostream>
using namespace std;
int main()
{
	int n,i;
	float s,t;
	cin>>n;
	s=0;t=1;
	for(i=1;i<=n;i++)
	{
		t*=i;
		s+=t;
	}
	cout<<s<<endl;
}