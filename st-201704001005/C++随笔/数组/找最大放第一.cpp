#include<iostream>
using namespace std;
int main()
{
	int n,i,t,w,max,a[50];
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	w=0;
	for(i=1;i<n;i++)
		if(a[w]<a[i])w=i;
		if(w!=0)
		{
			t=a[0];a[0]=a[w];a[w]=t;
		}
		for(i=0;i<n;i++)
			cout<<a[i]<<" ";
		cout<<endl<<"第"<<w+1<<"个最大"<<endl;
}