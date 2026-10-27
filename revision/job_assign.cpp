#include<bits/stdc++.h>
using namespace std;

int c[100][100], n, best=INT_MAX, used[100];
void solve(int i, int sum){
    if (sum>=best ) return;
    if(i==n) {
        best=sum;
        return;
    }
    for(int j=0;j<n;j++){
        if(!used[j]){
            used[j]=1;
            solve(i+1, sum+c[i][j]);
            used[j]=0;
        }
    }

}
int main(){
    cin>>n;
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>c[i][j];

    solve(0,0);
    cout<<"Minimum cost: "<<best;
    return 0;
}