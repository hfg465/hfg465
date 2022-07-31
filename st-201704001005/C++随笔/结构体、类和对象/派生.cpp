#include <iostream.h>
//基类的声明部分
class CStudent
{ public:
	void CalAver();
	CStudent();
	~CStudent();
  	int no;
	float cj[3];
};
//基类的函数实现部分
void CStudent::CalAver()
 { float pj;
    pj=cj[0]+cj[1]+cj[2];  
   cout<<no<<"pj="<<pj/3; }
CStudent::CStudent()
{   no=1001;
    cj[0]=90;cj[1]=80;cj[2]=85;  }
CStudent::~CStudent()   { }
//派生类的声明部分
class CNS:public CStudent
{public:
    void SetData();
};
//派生类的函数实现部分
void CNS::SetData()
{   cout<<"请输入数据\n";
     cin>>no;
     cin>>cj[0]>>cj[1]>>cj[2];
}
//定义对象使用派生类
int main()
{     CNS s;
      s.SetData();
      s.CalAver();
	  cout<<endl;
}
