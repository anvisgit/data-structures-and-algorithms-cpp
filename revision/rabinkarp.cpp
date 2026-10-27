#include<bits/stdc++.h>
using namespace std;

int main() {
    string T, P;
    cin >> T >> P;
    int n = T.length();
    int m = P.length();
    int d = 256;
    int q = 101;
    int h = 1;
    int p = 0;
    int t = 0;
    int found=0;
    for(int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    for(int i = 0; i < m; i++) {
        p = (d * p + P[i]) % q;
        t = (d * t + T[i]) % q;
    }

    for(int i = 0; i <= n - m; i++) {
        if(p == t) {
            int j;
            for(j = 0; j < m; j++) {
                if(T[i + j] != P[j])
                    break;
            }

            if(j == m)
                cout << " index " << i << endl;
        }

        if(i < n - m) {
            int t1=t-T[i]*h;
            t = (d *t1 + T[i+m])%q;

            if(t < 0)
                t += q;
        }
    }

    return 0;
}