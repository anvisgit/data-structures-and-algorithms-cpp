#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
long long func(long long x, long long y){
  if(x<10||y<10){
    return x*y;
  }
  int n=max((int)log10(x), (int)log10(y));
  int m=n/2;
  int p=pow(10,m);
  long long a=x/p;
  long long b=x%p;
  long long c=y/p;
  long long d=x%p;
  long long ac = karatsuba(a, c);
  long long bd = karatsuba(b, d);
  long long abcd = karatsuba(a + b, c + d);
  return ac * pow(10, 2 * m)+ (abcd - ac - bd) * p+ bd;
}
int main() {
    long long x, y;
    cout << "Enter two numbers: ";
    cin >> x >> y;
    cout << "Product = " << karatsuba(x, y) << endl;
    return 0;
}
