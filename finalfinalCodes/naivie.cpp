#include<stdc++.h>
using namespace std;
int main(){
string T,P;
    cout<<"Enter text: ";
    cin>>T;
    cout<<"Enter pattern: ";
    cin>>P;
    int found=0;

    int n=T.length();
    int m=P.length();
    for(int i=0;i<n-m;i++){
        for(int j=0;j<m;){
            if(T[i+j]!=P[j]){
                break;
            }
            if(j==m){
                cout<<"found at i: "<<i<<endl;
                found=1
            }
            

        }
    }
}