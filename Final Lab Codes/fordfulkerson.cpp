#include<bits/stdc++.h>
using namespace std;

int cap[100][100];
int parent[100];int visited[100];
int n, m
bool trav(int u, int t){
    visited[u]=1;
    if(u==t){
        return true;
    }
    for(int v=0;v<n;v++){
        if(cap[u][v]>0&&visited[v]==0){
            parent[v]=u;
            visited[v]=1;
        }
        if(trav(v,t)){
            return true;
        }

    }
    return false;
}

int main(){
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>cap[i][j];
        }
    }
    int maxflow=0;
    while(true){
        for(int i=0;i<n;i++){
            parent[i]=-1;
            visited[i]=0;

        }
        if(trav(s,t)==false){
            break;
        }
        int flow=INT_MAX;
        for(int v=t;v!=s;v=parent[v]){
            int u=parent[v];
            flow=min(flow, cap[u][v]);
        }
        for(int v=t;v!=s;v=parent[v]){
            int u=parent[v];
            cap[u][v]-=flow;
            cap[v][u]+=flow;
        }

        maxflow+=flow;

    }
    cout<<maxflow<<endl;
    return 0;
}