#include <iostream.h>
//�������������
class CStudent
{ public:
	void CalAver();
	CStudent();
	~CStudent();
  	int no;
	float cj[3];
};
//����ĺ���ʵ�ֲ���
void CStudent::CalAver()
 { float pj;
    pj=cj[0]+cj[1]+cj[2];  
   cout<<no<<"pj="<<pj/3; }
CStudent::CStudent()
{   no=1001;
    cj[0]=90;cj[1]=80;cj[2]=85;  }
CStudent::~CStudent()   { }
//���������������
class CNS:public CStudent
{public:
    void SetData();
};
//������ĺ���ʵ�ֲ���
void CNS::SetData()
{   cout<<"����������\n";
     cin>>no;
     cin>>cj[0]>>cj[1]>>cj[2];
}
//�������ʹ��������
int main()
{     CNS s;
      s.SetData();
      s.CalAver();
	  cout<<endl;
}
