#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int p[100];
    for(int i=0;i<=n;i++){
        cin>>p[i];
    }
    int dp[100][100];


    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                dp[i][j]=0;
            }
            else{
                dp[i][j]=INT_MAX;
            }
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=i+1;j<=n;j++){
            for(int k=i;k<j;k++){
                int cost=dp[i][k]+dp[k+1][j]+p[i-1]*p[j]*p[k];
                dp[i][j]=min(dp[i][j], cost);
            }
        }
    }
    cout<<dp[1][n];
    return 0;
}