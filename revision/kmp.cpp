#include<bits/stdc++.h>
using namespace std;
void compute(string p, int lps[]){
    int m=p.length();
    lps[0]=0;
    int len=0;
    for(int i=1;i<m;i++){
        if(p[i]==p[len]){
            len++;
            lps[i]=len;
            i++
        }
        else {
            if(len!=0){
                len=lps[len-1]
            }
            else{
                lps[len]=0;
                i++;
            }
        }
    }
}
int main(){
    string T;
    cin>>T;
    string P;
    cin>>P;
    int lps[100]={0};
    int n=T.length();
    int m=T.length();
    compute(lps, P);
    int j=0;
    for(int i=0;i<n-m;i++){
        if(T[i]==P[j]){
            i++;
            j++;
        }
        if(j==m){
            cout<<i<<endl;
            j=lps[j-1]
        }
        else if(i<n-m){
            if(T[i]!=P[j]){
                if(j!=0){
                    j=lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        
    }
    return 0;
    
}