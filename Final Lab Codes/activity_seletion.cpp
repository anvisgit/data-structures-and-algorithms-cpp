
#include<bits/stdc++.h>
using namespace std;

struct act{
    int id;
    int start;
    int finish;
};
bool compare(act a, act b){
    return a.finish <= b.finish;
}
void selection(act a[], int n){
    sort(a, a+n, compare);
    int count=1;
    int last=a[0].finish;

    cout<<"Selected activity: "<<a[0].id<<endl;

    for(int i=1;i<n;i++){
        if(a[i].start>=last){
            last=a[i].finish;
            count++;
            cout<<"Selected activity: "<<a[i].id<<endl;
        }
    }

    cout<<"Total activities: "<<count<<endl;
}

int main(){
    cout<<"Enter the number of activities: "<<endl;
    int n;
    cin>>n;
    act a[100];
    cout<<"Enter start and finish time: "<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i].start>>a[i].finish;
        a[i].id=i+1;
    }

    selection(a,n);

    return 0;
}
