#include<cmath>
#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace sd;
long long mult(long  long x,long long y){
    if(x<10||y<10){
        return x*y;
    }
    int n=max((int)log10(x), (int)log10(y))+1;
    int m=floor(n/2);

    long long p = 1;
    for (int i = 0; i < m; i++) {
        p *= 10;
    }
    
    long long a=x/p;
    long long b=x%p;
    long long c=y/p;
    long long d=y%p;

    long long ac=mult(a,c);
    long long bd=mult(b,d);
    long long abcd=mult(a+b,c+d);
    return ac*p*p+bd+(abcd-ac-bd)*p;

}

int main(){
    long long x;
    long long y;
    cin>>x;
    cin>>y;
    cout<<mult(x,y)<<endl;
    return 0;
}
