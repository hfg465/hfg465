//��������Ϥ�ṹ���ʹ�á������ܣ�����һ��ѧ����������4�ſγ̵ĳɼ��������ƽ����
#include<iostream>
using namespace std;
int main()
{
	struct student
	{
		char name[20];
		float score[4];
		float aver;
	};
	student st1,*p;
	int i;
	p=&st1;
	cin>>st1.name;
	st1.aver=0;
	for(i=0;i<4;i++)
	{
		cin>>st1.score[i];
		st1.aver+=st1.score[i];
	}
	st1.aver/=4;
	cout<<st1.name<<" ";
	for(i=0;i<4;i++)
		cout<<st1.score[i]<<" ";
	cout<<st1.aver;
	cout<<endl;
	cout<<p->name;
}