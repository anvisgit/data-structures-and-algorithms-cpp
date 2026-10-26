
#include<bits/stdc++.h>
using namespace std;

int graph[20][20];
int color[20];

bool safe(int v,int c,int n){
    for(int i=0;i<n;i++){
        if(graph[v][i]==1 && color[i]==c)
            return false;
    }
    return true;
}
bool solve(int v,int n,int m){
    if(v==n)
        return true;
    for(int c=1;c<=m;c++){
        if(safe(v,c,n)){
            color[v]=c;

            if(solve(v+1,n,m))
                return true;

            color[v]=0;
        }
    }

    return false;
}

int main(){
    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>graph[i][j];
        }
    }
    if(solve(0,n,m)){
        for(int i=0;i<n;i++){
            cout<<"Vertex "<<i<<" : Colour "<<color[i]<<endl;
        }
    }
    else{
        cout<<"No solution"<<endl;
    }

    return 0;
}
