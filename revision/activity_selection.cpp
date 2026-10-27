#include<bits/stdc++.h>
using namespace std;
struct Activity {
    int start, finish;
};
bool cmp(Activity a, Activity b) {
    return a.finish < b.finish;
}
int main() {
    int n;
    cin >> n;
    Activity a[100];
    for(int i = 0; i < n; i++) {
        cin >> a[i].start >> a[i].finish;
    }
    sort(a, a + n, cmp);

    cout << a[0].start << " " << a[0].finish << endl;
    int last = a[0].finish;

    for(int i = 1; i < n; i++) {
        if(a[i].start >= last) {
            cout << a[i].start << " " << a[i].finish << endl;
            last = a[i].finish;
        }
    }

    return 0;
}
