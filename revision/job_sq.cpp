#include<bits/stdc++.h>
using namespace std;

struct Job {
    char id;
    int deadline, profit;
};
bool cmp(Job a, Job b) {
    return a.profit > b.profit;
}
int main() {
    int n;
    cin >> n;
    Job a[100];
    for(int i = 0; i < n; i++) {
        cin >> a[i].id >> a[i].deadline >> a[i].profit;
    }
    sort(a, a + n, cmp);
    int slot[100];
    for(int i = 0; i < 100; i++) {
        slot[i] = -1;
    }
    
    int total = 0;

    for(int i = 0; i < n; i++) {
        for(int j = a[i].deadline; j > 0; j--) {
            if(slot[j] == -1) {
                slot[j] = i;
                total += a[i].profit;
                break;
            }
        }
    }

    for(int i = 1; i < 100; i++) {
        if(slot[i] != -1) {
            cout << a[slot[i]].id << " ";
        }
    }

    cout << "\nTotal Profit: " << total;

    return 0;
}