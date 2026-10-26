#include<iostream>
#include<algorithm>
using namespace std;

struct Item{
double p;
double w;
};
bool compare(Item a, Item b){
  return (a.p/a.w)>(b.p/b.w);
}
int main(){
  int n;
  cin>>n;
  Item items[n];
  for(int i=0;i<n;i++){
    cin>> items[i].p>>items[].w;
  }
  double cap;
  cin>>cap;
  
  int r[n]=0;
  for(int i=0;i<n;i++){
    r[i]=items[i].p/items[i].w;
  }
  sort(items, items +n ,compare);
  double profit=0;
  for(int i=0;<n;i++){
    if (items[i].w<cap{
      cap-=items[i].w;
      profit+=items[i].p;}
    else{
      profit+=(items[i].p*cap/items[i].w);
      cap=0;
      break
  }
  cout<<"profit"<<profit<<endl;
  return 0;
}



