#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int u[100], v[100], w[100], d[100];

    for(int i = 0; i < m; i++)
        cin >> u[i] >> v[i] >> w[i];

    int src;
    cin >> src;

    for(int i = 0; i < n; i++)
        d[i] = INT_MAX;

    d[src] = 0;

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < m; j++) {
                d[v[j]] = min(d[v[j]], d[u[j]] + w[j]);
        }
    }

    for(int j = 0; j < m; j++) {
        if(d[u[j]] != INT_MAX && d[u[j]] + w[j] < d[v[j]]) {
            cout << "Negative cycle";
            return 0;
        }
    }

    for(int i = 0; i < n; i++)
        cout << i << " : " << (d[i] == INT_MAX ? -1 : d[i]) << endl;

    return 0;
}