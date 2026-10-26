#include<bits/stdc++.h>
using namespace std;
int crossar(int arr[], int low, int mid, int high){
    int lsum=INT_MIN;
    int rsum=INT_MIN;
    int sum=0;
    for(int i=mid;i>=low;i--){
        sum+=arr[i];
        lsum=max(sum, lsum);
    }
    sum=0;
    for(int i=mid+1;i<=high;i++){
        sum+=arr[i];
        rsum=max(rsum,sum);
    }
    return lsum+rsum;
}

int maxar(int arr[], int low, int high){
    if(high==low){
        return arr[low];
    }
    int mid= low+(high-low)/2;
    int lc=maxar(arr, low, mid);
    int rc=maxar(arr, mid+1, high); 
    int cc=crossar(arr, low, mid, high);
    return max(lc,max(rc,cc));

}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<maxar(arr,0,n-1)<<endl;
    return 0;
}