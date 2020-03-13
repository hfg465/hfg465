#include <iostream>
using namespace std;
int a,b;
void swap( )
{ 
	int t;
  t=a;   
  a=b;
  b=t;   
}
int main( )
{ 
	a=5,b=10;  
  cout<<a<<","<<b<<endl;  
  swap();
  cout<<a<<","<<b<<endl; 
}
