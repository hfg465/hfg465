/*【问题描述】有一分段函数如下，请编写程序，输入x值，输出y值。
 
【样例输入】-1
【样例输出】-1.4597
【样例输入】-0.5
【样例输出】1.5874
【样例输入】1.57
【样例输出】0.999999*/
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	float x,y;
	cin>>x;
	if(x<=-1)y=2*x+cos(x);
	else if(x<1)y=1.0/pow(x+1,2.0/3.0);
	else y=sin(x)*sin(x);
	cout<<y<<"\n";
}