#include <iostream>
#include <string>
using namespace std;

void rabinkarp(string txt, string ptr, int d, int q) {
    int n = txt.length();
    int m = ptr.length();
    if (m > n) {
        cout << "Cannot be found" << endl;
        return;
    }
    int h = 1;
    int p = 0;
    int t = 0;

    for (int i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }
    for (int i = 0; i < m; i++) {
        p = (d * p + ptr[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (int i = 0; i <= n - m; i++) {
        if (p == t) {
            for (int j = 0; j < m && ptr[j] == txt[i + j]; j++)
            if (j == m) {
                cout << "Pattern  at index " << i << endl;
            }
        }

        if (i < n - m) {
            t = (d * (t - txt[i] * h) + txt[i + m]) % q;

            if (t < 0) {
                t += q;
            }
        }
    }
}
