// For each station:

// a[i][j] → processing time at station j on line i
// t[i][j] → transfer time from line i to the other line after station j
// e[i] → entry time
// x[i] → exit time

// Define:
//  minimum time to reach station j on line 1.
//  minimum time to reach station j on line 2.
#include<iostream>
#include<algrithm>
using namespace std;
int main(){
    int n;
    cout << "Enter number of stations: ";
    cin >> n;
    int e[2], x[2];
    int a[2][n];
    int t[2][n];
    cout << "Enter entry times: ";
    cin >> e[0] >> e[1];

    cout << "Enter processing times for Line 1: ";
    for (int i = 0; i < n; i++)
        cin >> a[0][i];

    cout << "Enter processing times for Line 2: ";
    for (int i = 0; i < n; i++)
        cin >> a[1][i];

    cout << "Enter transfer times Line 1 -> Line 2: ";
    for (int i = 0; i < n - 1; i++)
        cin >> t[0][i];

    cout << "Enter transfer times Line 2 -> Line 1: ";
    for (int i = 0; i < n - 1; i++)
        cin >> t[1][i];

    cout << "Enter exit times: ";
    cin >> x[0] >> x[1];

    int dp1=e[0]+a[0][0];
    int dp2=e[1]+a[1][0];
    for(int i=1;i<n;i++){
      int dp1n=min(dp1+a[0][i],dp2+t[0][i-1]+a[1][i]);
      int dp2n = min(dp2 + a[1][i],dp1 + t[0][i - 1] + a[1][i]);
    }
    dp1=dp1n;
    dp2=dp2n;
    int ans = min(dp1 + x[0], dp2 + x[1]);
    cout<<"ans: "<<ans<<endl;
    return 0;

  
}
