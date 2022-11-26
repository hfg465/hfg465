#include  <iostream>
using namespace std;
int main( )
{ 
	int x=2,y=3,z;
  int tr(int,int);
  z=tr(x,5);
  cout<<"\n(2)x="<<x<<"y="<<y<<"z="<<z; 
}
int  tr(int x,int y)
{ 
	float z;
  x*=x;y*=y;
  z=(x+y)/2;
  cout<<"(1)x="<<x<<"y="<<y<<"z="<<z<<endl; 
  return z;  
 }