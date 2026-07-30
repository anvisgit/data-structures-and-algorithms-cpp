#include <iostream>
#include <cmath>
#include<algorithm>
using namespace std;
long long karatsuba( long long x, long long y){
  if(x<10||y<10){
    return x*y;
  }
  int n=max((int)log10(x), (int)log10(y))+1;
  int m=n/2;
  long long p=pow(10, m);
  long long a=x/p;
  long long b=x%p;
  long long c=y/p;
  long long d=y%p;
  long long ac=karatsuba(a,c);
  long long bd=karatsuba(b,d);
  long long abcd=karatsuba(a+b, c+d);
  return ac*pow(10, 2*m)+(abcd-ac-bd)*p+bd;
}
int main(){
  long long x,y;
  cout<<"Enter 2 numbers:";
  cin>>x>>y;
  cout<<"\nproduct="<<karatsuba(x,y)<<endl;
  return 0;
}

