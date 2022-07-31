/*【问题描述】已知 ，计算该序列的前N项和SN，直到SN 大于q为止，q由键盘输入。
【输入形式】一个实型数据
【输出形式】一个实型数据
【样例输入】50 
【样例输出】50.4167
【样例说明】随着项数的增加，SN的值也在增大，SN超过50后的第一个值是50.4167*/
#include<iostream>
using namespace std;
int main()
{
	int q,n=1;
	float s=0;
	cin>>q;
	while(s<=q)
	{
		s+=1.0*(n+1)/n;
		n++;
	}
	cout<<s<<endl;
}