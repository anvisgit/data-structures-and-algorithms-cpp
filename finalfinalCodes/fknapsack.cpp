#include<bits/stdc++.h>
using namespace std;

struct items{
    int wt;
    int prft;
};

bool cmp(items a, items b){
    double r1=(double)a.prft/a.wt;
    double r2=(double)b.prft/b.wt;
    return r1>r2;
}

int main(){
    int n;
    cin>>n;

    items arr[100];

    for(int i=0;i<n;i++){
        cin>>arr[i].wt>>arr[i].prft;
    }

    int cap;
    cin>>cap;

    sort(arr,arr+n,cmp);

    double tp=0.0;
    int bag=cap;

    for(int i=0;i<n;i++){
        if(bag>=arr[i].wt){
            tp+=arr[i].prft;
            bag-=arr[i].wt;
        }
        else{
            tp+=(double)arr[i].prft/arr[i].wt*bag;
            bag=0;
            break;
        }
    }

    cout<<tp<<endl;
    return 0;
}