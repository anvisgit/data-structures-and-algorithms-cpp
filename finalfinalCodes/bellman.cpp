#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int u,v,w;
};

int main(){
    int n,m;
    cin>>n>>m;

    Edge edge[100];

    for(int i=0;i<m;i++){
        cin>>edge[i].u>>edge[i].v>>edge[i].w;
    }

    int src;
    cin>>src;

    int d[100];

    for(int i=0;i<n;i++){
        d[i]=INT_MAX;
    }

    d[src]=0;

    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int u=edge[j].u;
            int v=edge[j].v;
            int w=edge[j].w;

            if(d[u]!=INT_MAX){
                d[v]=min(d[v],d[u]+w);
            }
        }
    }

    for(int j=0;j<m;j++){
        int u=edge[j].u;
        int v=edge[j].v;
        int w=edge[j].w;

        if(d[u]!=INT_MAX && d[u]+w<d[v]){
            cout<<"Negative cycle";
            return 0;
        }
    }

    for(int i=0;i<n;i++){
        if(d[i]==INT_MAX)
            cout<<i<<" : INF"<<endl;
        else
            cout<<i<<" : "<<d[i]<<endl;
    }

    return 0;
}