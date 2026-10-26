
#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of matrices: ";
    cin>>n;

    int p[100]; // Dimensions: matrix Ai has size p[i-1] x p[i]

    cout<<"Enter "<<n+1<<" dimensions: ";
    for(int i=0;i<=n;i++)
        cin>>p[i];

    int d[100][100]; // Minimum multiplication cost from Ai to Aj

    // A single matrix requires zero multiplications
    for(int i=1;i<=n;i++)
        d[i][i]=0;

    // len = length of the matrix chain
    for(int len=2;len<=n;len++){
        for(int i=1;i<=n-len+1;i++){
            int j=i+len-1;
            d[i][j]=INT_MAX;

            // Try every possible split position
            for(int k=i;k<j;k++){
                int cost=d[i][k]+d[k+1][j]+p[i-1]*p[k]*p[j];
                d[i][j]=min(d[i][j],cost);
            }
        }
    }

    cout<<"Minimum cost: "<<d[1][n]<<endl;
    return 0;
}
