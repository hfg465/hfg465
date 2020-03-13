/*【问题描述】输入一行字符，以字符0作为结束标志，输出这行字符对应的ASCII码值之和。 
【输入形式】若干个字符，以字符0结束
【输出形式】一个正整数
【样例输入】ABCDE0
【样例输出】335
【样例说明】字符'A'、字符'B'、字符'C'、字符'D'、字符'E'的ASCII码之和为335，注意字符'0'的
ASCII码值不算在内*/
#include<iostream>
using namespace std;
int main()
{
	char x;
	float s=0;
	cin>>x;
	while(x!='0')
	{
		s+=x;
		cin>>x;
	}
	cout<<s<<endl;
}