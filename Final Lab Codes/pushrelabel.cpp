#include<bits/stdc++.h>
using namespace std;

int cap[100][100];
int h[100];
int excess[100];

void push(int u,int v){
    int f=min(excess[u], cap[u][v]);
    cap[u][v]-=f;
    cap[v][u]+=f;
    excess[v]+=f;
    excess[u]-=f;

}
void relabel(int u, int n){
    int mn=INT_MAX;
    for(int v=0;v<n;v++){
        if(cap[u][v]>0){
            mn=min(mn, h[v]);
        }
    }
    if(mn!=INT_MAX){
        h[u]=mn+1;
    }
}
int maxflow(int n, int s, int t){
    h[s]=n;
    for(int v=0;v<n;v++){
        if(cap[s][v]>0){
            push(s,v);
        }
    }
    while(true){
        u=-1;
        for(int i=0;i<n;i++){
            if(i!=s&&i!=t&&excess[i]>0){
                u=i;
                break;
            }
        }
        if(u==-1){
            break;
        }
        bool pushed=false;
        for(int v=0;v<n;v++){
            if(cap[u][v]>0&&h[u]==h[v]+1){
                push(u,v);
                pushed=true;
                break;
            }
        }
        if(!pushed){
            relabel(u,n);
        }
    }
    return excess[t];
}
int main() {
    int n, m;
    cin >> n >> m; 
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        cap[u][v] += c;
    }
    int s, t;
    cin >> s >> t;
    cout << maxFlow(n, s, t) << '\n';
    return 0;
}
