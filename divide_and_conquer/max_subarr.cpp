// given an arr[n], find contiguous sub arr w max sums
#include<iostream>
#include<algorithm>
using std namespace;
int maxarr(int arr[], int low, int high){
  if(high==low){
    return arr[low];
  }
  int mid=low+(high-low)/2;
  int l=maxarr( arr, low, mid);
  int r=max(arr, mid+1, high);
  int c=crossmax(arr, low, mid, high);
  return max(l,c,r);
}
int crossmax(int arr[], l,m,h){
  int lsum=-10000;
  int rsum=-10000;
  int sum=0;
  for(int i=low;i<=mid;i++){
    sum+=arr[i]
    lsum=max(sum, lsum);
  }
   for(int i=mid+1;i<=high;i++){
    sum+=arr[i]
    rsum=max(sum, rsum);
  }
  return lsum+rsum;
  
}
int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cout<<"ans: "<<maxarr(arr,0,n-1)<<endl;
  return 0;
}
