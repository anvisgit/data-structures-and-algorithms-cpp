#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int n;
  cout<<"enter n.o. stations:"<<endl;
  cin>>n;
  int e[2], x[2];
  int a[2][100], t[2][100];
  cout<<"enter entry time for l1, l2"<<endl;
  cin>>e[0]>>e[1];
  cout<<"enter processing time for l1"<<endl;
  for(int i=0;i<n;i++){
    cin>>a[0][i];
  }
  cout<<"enter processing time for l2"endl;
  for(int i=0;i<n;i++){
    cin>>a[1][i];
  }
  cout<<"enter transfer time, l1->l2"<<endl;
  for(int i=0;i<n;i++){
    cin>>t[0][i];
  }
  cout<<"enter transfer time, l2->l1"<<endl;
  for(int i=0;i<n;i++){
    cin>>t[1][i];
  }
  cout<<"enter exit time for l1, l2"<<endl;
  cin>>x[0]>>x[1];
  int p1=e[0]+a[0][0];
  int p2=e[1]+a[1][0];
  for(int i=1;i<ni++){
    int newp1=min(p1+a[0][i], p2+a[1][i]+t[0][i-1]);
    int newp2=min(p2+a[1][i],p1+a[0][i]+t[1][i-1]);
    p1=newp1;
    p2=newp2;
  }
  int ans=min(p1+x[0]+p2+x[1]);
  cout<<"min p time: "<<ans<<endl;
  return 0;
}
