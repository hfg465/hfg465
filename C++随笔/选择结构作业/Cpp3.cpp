/*【问题描述】有一分段函数如下，请编写程序，输入x值，输出y值。
 
【样例输入】-2.5
【样例输出】7.36396
【样例输入】1
【样例输出】2
【样例输入】11
【样例输出】0.222681*/
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	float x,y;
	cin>>x;
	if(x<=-1)y=3*sqrt(fabs(x)+2)+1;
	else if(x<=10)y=pow(x,5)+1;
	else y=sqrt((x+1)/(2*x*x));
	cout<<y<<"\n";
}