#include<bits/stdc++.h>
using namespace std;

int cap[100][100], h[100], excess[100], n;

void push(int u, int v) {
    int f = min(excess[u], cap[u][v]);

    cap[u][v] -= f;
    cap[v][u] += f;

    excess[u] -= f;
    excess[v] += f;
}

void relabel(int u) {
    int mn = INT_MAX;

    for(int v = 0; v < n; v++) {
        if(cap[u][v] > 0)
            mn = min(mn, h[v]);
    }

    if(mn != INT_MAX)
        h[u] = mn + 1;
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> cap[i][j];

    int s, t;
    cin >> s >> t;

    h[s] = n;

    for(int v = 0; v < n; v++) {
        if(cap[s][v] > 0) {
            excess[v] = cap[s][v];
            excess[s] -= cap[s][v];

            cap[v][s] += cap[s][v];
            cap[s][v] = 0;
        }
    }

    while(true) {
        bool changed = false;

        for(int u = 0; u < n; u++) {
            if(u == s || u == t || excess[u] <= 0)
                continue;

            for(int v = 0; v < n; v++) {
                if(cap[u][v] > 0 && h[u] == h[v] + 1) {
                    push(u, v);
                    changed = true;
                    break;
                }
            }

            if(excess[u] > 0) {
                relabel(u);
                changed = true;
            }
        }

        if(!changed)
            break;
    }

    cout << excess[t];

    return 0;
}