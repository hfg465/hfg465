#include<iostream>
using namespace std;
int main()
{
	struct table
	{
		int num;
		char name[20];
		float score[4];
	};
	table tt[3];
	
	int i,k;
	for(i=0;i<3;i++)
		cin>>tt[i].num>>tt[i].name;
	for(i=0;i<3;i++)
		for(k=0;k<4;k++)
			cin>>tt[i].score[k];
		for(i=0;i<3;i++)
		{
			cout<<tt[i].num<<","<<tt[i].name<<",";
			for(k=0;k<4;k++)
				cout<<tt[i].score[k]<<" ";
			cout<<endl;
		}
}