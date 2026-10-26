#include<bits/stdc++.h>

using namespace std; 
struct Activity{
    int id;
    int start;
    int finish;
};
bool comp(Activity a, Activity b){
    return (a.finish<=b.finish);
}
void selection(Activity a[], int n){
    sort(a,a+n, comp);
    int lastfinish=a[0].finish;
    int count=1;
    cout<<"Activity: "<<a[0].id<<endl;
    for(int i=0;i<n;i++){
        if(a[i].start>=lastinish){
            cout<<"Activity: "<<a[i].id<<endl;
            lastfinish=a[i].finish;
            count++;
        }
    }
    cout<<"Total activities selected: "<<count<<endl;

}
int main(){
    int n;
    cout<<"Enter the number of activities: "
    cin>>n;
    Activity a[n];
    cout<<"Enter the start and finish time of activities: "<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i].start>>a[i].finish;
        a[i].id=i;
    }
    selection(a,n);
    return 0;
}