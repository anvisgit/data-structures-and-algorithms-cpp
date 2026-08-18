#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  cout<<"enter the number of matrices:"<<endl;
  int n;
  cin>>n;

  int p[100];//dimention arr-> matrix Ai has dimn p[i-1]*p[i]
  cout<<"enter"<<n+1<<"dimentions"<<endl;
  for(int i=0;i<=n;i++){
    cin>>p[i]
  }
  d[100][100]; //min scalar mul cost 
  for (int i = 1; i <= n; i++)
      d[i][i] = 0;
  for( int len=2;len<=n;len++){
    for(int i=1;i<=n-len+1;i++){
      int j=len+i-1;
      d[i][j]=10000;
      for(int k=i;k<j;k++){
        int cost=d[i][k];+d[k+1][j]++p[i-1]*p[k]*p[j];
        d[i][j]=min(d[i][j],cost);
      }
    }
  }
  cout<<"min cost: "<<d[1][n]<<endl;
  return 0;
  
}
