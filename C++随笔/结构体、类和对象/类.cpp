#include<iostream>
using namespace std;
class CStudent//������
{
public:
	void CalAver();
	CStudent();//���캯��(������������ͬ)
	~CStudent();//��������(������������ͬ)
	int no;
	float cj[3];
};
void CStudent::CalAver()
{
	float pj;
	pj=cj[0]+cj[1]+cj[2];
	cout<<no<<" "<<pj/3<<endl;
}
CStudent::CStudent()//���캯��ʵ�ֲ���(�������п���)
{
	int i;
	no=1010;
	cj[0]=90.5;cj[1]=89.6;cj[2]=97.4;
}
CStudent::~CStudent()//��������ʵ�ֲ���(û�в���)
{}
class CNS:public CStudent//�̳к����� ������
{public:
   void SetDate();
   CNS();
};
void CNS::SetDate()
{
	cout<<"����������:";
	cin>>no;
	cin>>cj[0]>>cj[1]>>cj[2];
}
CNS::CNS()//������Ĺ��캯��
{
	no=1000;
	cj[0]=1;cj[1]=2;cj[2]=3;
}
int main()//��������ִ�����
{
	CNS t,s,*p;
	t.SetDate();
	s.CalAver();
	p=&s;
	p->CalAver();
}