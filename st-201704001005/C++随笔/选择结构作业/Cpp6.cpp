/*【问题描述】编写程序计算某年某月的天数。输入年份year和月份month,输出该月份的天数。 
【输入形式】两个数字，中间用空格隔开
【输出形式】一个数字
【样例输入】2012 2
【样例输出】29
【样例说明】2012年2月有29天*/
#include<iostream>
using namespace std;
int main()
{
	int year,month,days;
	cin>>year>>month;
	if(year%4==0&&month==2)
		days=29;
	if(year%4!=0&&month==2)
		days=28;
	if(month!=2)	
	{
		if(month<=7)
		{
			if(month%2==0)days=30;
			else days=31;
		}
		else
		{
			if(month%2==0)days=31;
			else days=30;
		}
	}
		cout<<days<<"\n";
}
