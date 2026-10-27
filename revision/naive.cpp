#include<bits/stdc++.h>
using namespace std;

int main() {
    string T, P;
    cin >> T >> P;

    int n = T.length();
    int m = P.length();

    for(int i = 0; i <= n - m; i++) {
        int j;

        for(j = 0; j < m; j++) {
            if(T[i + j] != P[j])
                break;
        }

        if(j == m) {
            cout << "Pattern found at index " << i << endl;
        }
    }

    return 0;
}