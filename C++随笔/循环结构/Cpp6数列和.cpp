/*��������������֪ ������S��ֵ��ֱ��ĳһ��ľ���ֵС��eΪֹ��С��e������ۼӣ���e��
�������롣
��������ʽ��e��ֵ
�������ʽ��S��ֵ
���������롿1E-4
�����������0.866924*/
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