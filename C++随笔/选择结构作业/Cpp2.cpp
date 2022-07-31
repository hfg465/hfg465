/*【问题描述】编写一个程序，当用户输入一个小数（正值浮点数）后，将小数转化为最近的整数输
出（四舍五入）。
【输入形式】用户在第一行输入一个小数
【输出形式】用户在下一行显示输出结果
【样例输入】3.47
【样例输出】3
【样例说明】与输入值3.47接近的整数为3和4，3.47比3.5小，舍掉小数部分，结果为3。*/
#include<iostream>
using namespace std;
int main()
{
	float x,m;
	int y;
	cin>>x;
	y=int(x);
	m=y+0.5;
	if(x<m)
		cout<<y<<endl;
	else cout<<y+1<<endl;
}