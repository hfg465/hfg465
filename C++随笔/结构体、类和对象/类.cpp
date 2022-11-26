#include<iostream>
using namespace std;
class CStudent//定义类
{
public:
	void CalAver();
	CStudent();//构造函数(名字与类名相同)
	~CStudent();//析构函数(名字与类名相同)
	int no;
	float cj[3];
};
void CStudent::CalAver()
{
	float pj;
	pj=cj[0]+cj[1]+cj[2];
	cout<<no<<" "<<pj/3<<endl;
}
CStudent::CStudent()//构造函数实现部分(参数可有可无)
{
	int i;
	no=1010;
	cj[0]=90.5;cj[1]=89.6;cj[2]=97.4;
}
CStudent::~CStudent()//析构函数实现部分(没有参数)
{}
class CNS:public CStudent//继承和派生 派生类
{public:
   void SetDate();
   CNS();
};
void CNS::SetDate()
{
	cout<<"请输入数据:";
	cin>>no;
	cin>>cj[0]>>cj[1]>>cj[2];
}
CNS::CNS()//派生类的构造函数
{
	no=1000;
	cj[0]=1;cj[1]=2;cj[2]=3;
}
int main()//从上往下执行语句
{
	CNS t,s,*p;
	t.SetDate();
	s.CalAver();
	p=&s;
	p->CalAver();
}