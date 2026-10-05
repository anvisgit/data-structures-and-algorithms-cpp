#include<iosteam>
#include<vector>
using namespace std;
int b[20][20];
int isSafe(int r,int c, int n){
  for(int i=0;i<n;i++){ //check if q in col
    if(b[i][c])
      return false;
  }
  for(int i=r-1, j=c-1;i>=0&&j>=0;i--,j--){ //diag1
    if(b[i][c])
      return false;
  }
  for(int i=r-1, j=c+1;i>=0&&j<0;i--,j++){ //diag2
    if(b[i][c])
      return false;
  }
  return true
  
}
int soln(int r, int n){
  if(r==n)
    return true; // all q placed
  for(int i=0;i<n;i++){
    if(isSafe(r,i,n)){
      b[r][i]=1;// place if conditions satisfy
    if(soln(r+1, n)
      return true;
    b[r][i]=0;//backtrack
      
    }
  }
  return false;
}
int main(){
  int n;
  cin>>n;
  if(solve(0,n)){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cout<<b[i][j]<<" "<<;
      }
      cout<<endl;
    }
  }
  return 0;
}
