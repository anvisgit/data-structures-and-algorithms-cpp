#include<bits/stdc++.h>
using namespace std;

int graph[100][100];
int color[100];
int n,m;

bool isSafe(int v, int c){
    for(int i=0;i<n;i++){
        if(graph[v][i] && color[i]==c)
            return false;
    }
    return true;
}

bool solve(int v){
    if(v==n)
        return true;

    for(int c=1;c<=m;c++){
        if(isSafe(v,c)){
            color[v]=c;

            if(solve(v+1))
                return true;

            color[v]=0;
        }
    }

    return false;
}

int main(){
    cin>>n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>graph[i][j];
        }
    }

    cin>>m;

    if(solve(0)){
        for(int i=0;i<n;i++){
            cout<<"Vertex "<<i<<" : Colour "<<color[i]<<endl;
        }
    }
    else{
        cout<<"No solution";
    }

    return 0;
}