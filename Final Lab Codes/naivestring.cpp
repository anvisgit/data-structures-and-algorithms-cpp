#include<bits/stdc++.h>
using namespace std;
int main(){
    string txt, ptr;
    cin>>txt>>ptr;
    int n=txt.length();
    int m=ptr.length();
    for(int i=0;i<n-m;i++){
        for(int j=0;j<m;j++){
            if(txt[i+j]==ptr[j]){
                break;
            }
            if (j==m){
                cout<<"found at index: "<<i<<endl;
            }
        }
    }
    return 0;
}