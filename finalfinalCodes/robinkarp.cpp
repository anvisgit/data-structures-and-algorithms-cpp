
#include<bits/stdc++.h>
using namespace std;

int main(){
    string T,P;
    cout<<"Enter text: ";
    cin>>T;
    cout<<"Enter pattern: ";
    cin>>P;
    int n=T.length();
    int m=P.length();
    int d=256;
    int q=101;
    int p=0;
    int t=0;
    int found=0;
    int h=1;

    if(m>n){
        cout<<"not found"<<endl;
        return 0;
    }

    for(int i=0;i<m-1;i++){
        h=(h*d)%q;
    }

    for(int i=0;i<m;i++){
        p=(p*d+P[i])%q;
        t=(t*d+T[i])%q;
    }

    for(int i=0;i<=n-m;i++){
        if(p==t){
            int j;
            for(j=0;j<m;j++){
                if(P[j]!=T[i+j])
                    break;
            }

            if(j==m){
                cout<<i<<endl;
                found=1;
            }
        }

        if(i<n-m){
            int t1=t-T[i]*h;
            t=(t1*d+T[i+m])%q;
            if(t<0)
                t+=q;
        }
    }

    if(found==0)
        cout<<" not found"<<endl;

    return 0;
}
