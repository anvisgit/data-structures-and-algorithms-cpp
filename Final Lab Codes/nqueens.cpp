#include<bits/stdc++.h>
using namespace std;
int b[20][20];
bool safe(int row, int col){
    for(int i=0;i<row;i++){
        if(b[i][col]==1) return false;
    }
    for(int i=row-1,int j=col-1;i>=0&&j>=0;i--,j--){
        if(b[i][j]) return false;
    }
    for(int i=row-1, int j=col+1;i>=0&&j<n;i--,j++){
        if(b[i][j]) return false;
    }
    return true;
}
bool solve(int r, int n){
    if(r==n){
        return true;
    }
    for(int col=0;col<n;col++){
        if(safe(r,col)){
            b[r][col]=1;
            if(solve(r+1,n)){
                return true;
            }
            b[r][col]=0;
        }
    }
    return false;

}
int main(){
    int n;
    cin>>n;
    if (solve(0,n)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<b[i][j]<<" "
            }
            cout<<endl;
            return 0;
        }
    }
    return -1;
    

}