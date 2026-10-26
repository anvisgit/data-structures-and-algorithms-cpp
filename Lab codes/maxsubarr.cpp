#include<iostream>
#include<algorithm>
int maxCrosssingSum(int arr[], int low, int mid, int high){
  int lsum=-100;
  int sum=0;
  for(int i= mid;i<=low;i++){
      sum+=arr[i];
      if (lsum<sum){
        lsum=sum;
      }
    }
  int rsum=-100;
  sum=0;
  for(int i=mid+1;i<=high;i++){
    sum+=arr[i];
    if sum>rsum{
      rsum=sum;
      }
      
  }
  return lsum+rsum;
}
int func(int arr[], int low, int high){
  if (low==high){
    return arr[low];
  }
  int mid= low+(high-low)/2;
  int l=func(arr, low, mid);
  int r= func(arr, mid+1, high);
  int c=maxCrossingSum(arr, low, mid, high);
  return max(l,r,c);
}
int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
    
  }
  int res= func(arr, 0, n-1);
  cout<<res<<endl;
  return 0;
}
