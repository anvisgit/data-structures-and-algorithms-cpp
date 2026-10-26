#include<iostream>
using namespace std;
long long func( long long x, long long y){
  if(x<10||y<10){
    return x*y;
  }
  int n=max((int)log10(x), (int)log10(y));
  int m=n/2;
  long long p=pow(10,m);
  long long p2=pow(10,2*m);
  int a= x/p;
  int b=x%p;
  int c=y/p;
  int d=y%p;
  long long ac= func(a,c);
  long long bd=func(b,d);
  long long abcd=func(a+b,c+d);
  
  return ac*p2+(abcd-ac-bd)*p+bd;
  
}
int main(){
  long long x,y;
  cout<<"enter x,y"<<endl;
  cin>>x>>y;
  cout<<func(x,y)<<endl;
  return 0;
}
