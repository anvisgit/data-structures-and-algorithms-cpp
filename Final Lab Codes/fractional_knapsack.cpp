#include<cmath>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
struct Item{
    int wt;
    int prft;
};
bool comp(Item a, Item b){
    double r1=(double)a.prft/a.wt;
    double r2=(double)b.prft/b.wt;
    return r1<r2;
}
int main(){
    int n;
    cin>>n;
    Items arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].wt>>arr[i].prft;
    }
    int cap;
    cin>>cap;
    int bag=cap;
    double  totalprofit=0.0;
    sort(arr,arr+n,comp);
    for(int i=0;i<n;i++){
        if(arr[i].wt<=bag&&bag>=0){
            cout<<arr[i];
            bag-=arr[i].wt;
            totalprofit+=arr[i].prft;
        }
        else{
            totalprofit+=arr[i].prft/arr[i].wt*bag;
            break;
        }
    }

}