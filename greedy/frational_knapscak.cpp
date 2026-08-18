// given n items with attributes-> profit and weigjt, and a bag of capacity w; 
// fraction items allowed so max the profit in the bag

#include<iostream>
#include<algorithm>
using std namespace std;
struct Item{
  int p;
  int w;
};
int comp(Item a, Item b){
  return (a.p/a.w)>(b.p/b.w);
}
int main(){
  cout<<"enter number of items"<<endl;
  int n;
  cin>>n>>;
  cout<<"enter the capacity"<<endl;
  double cap;
  cin>>cap;
  cout<<"enter attributes associated w each item"<<endl;
  Item item[n];
  for(int i=0;i<n;i++){
    cin>> item[i].p>>cin>>item[i].w;
  }
  sort(item,item+n, comp)
  int tp=0;
  for(int i=0;i<n;i++){
    if(cap<item[i].p){
      tp+=item[i].p;
      cap-=item[i].w;
    }
    else{
      tp+=item[i].p*cap/item[i].w;
      cap=0;
      break;
    }
  }
  cout<<"maxprofit: "<<tp<<endl;
  return 0;
}
