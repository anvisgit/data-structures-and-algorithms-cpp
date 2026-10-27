#include<bits/stdc++.h>
using namespace std;
void compute(string p, int lps[]){
    int m=p.length();
    int len=0;
    lps[0]=0;

    for(int i=0;i<m;i++){
        if(p[i]==p[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len==0){
                lps[i]=0;
                i++;
            }
            else{
                len=lps[len-1];
            }
        }
    }
}
int main(){
    string T;
    string P;
    int n=T.length();
    int m=T.length();
    int lps[100]={0};
    compute(P,lps);
    int j=0;
    int found=0;
    for(int i=0;i<n;){
        if(T[i]==P[j]){
            i++;
            j++;
        }
        if(j==m){
            cout<<"found at : "<<i<<endl;
            found=1;
            j=lps[j-1];
        }
        else if(i<n&&T[i]!=p[j]){
            if(j==0){
                i++;
            }
            else{
                j=lps[j-1];
            }
        }
    }
    cout<<"not found:(("<<endl;
    return 0;

}