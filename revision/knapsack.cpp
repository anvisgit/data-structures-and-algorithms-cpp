#include<bits/stdc++.h>
using namespace std;
struct Items{
    int wt;
    int prft;
};
bool cmp(Items a, Items b){
    double r1=(double)a.prft/a.wt;
    double r2=(double)b.prft/b.wt;
    return r1>r2;
}
int main(){
    int n
    cin>>n;
    Items a[100];
    for(int i=0;i<n;i++){
        cin>>a[i].wt>>a[i].prft;
    }
    int cap;
    cin>>cap;
    double tp=0.0;
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++){
        if(cap>=a[i].wt){
            cap-=a[i].wt;
            tp+=a[i].prft;
        }
        else{
            tp+=(double)a[i].prft/a[i].wt*cap;
            cap=0;
            break;
        }
    }
    cout<<tp<<endl;
    return 0;

}