
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"enter n"<<endl;
    cin>>n;
    int e[2],x[2];
    int pt[2][n],tt[2][n];

    cout<<"enter entry time for l1,l2"<<endl;
    cin>>e[0]>>e[1];
    cout<<"enter processing time for l1"<<endl;
    for(int i=0;i<n;i++){
        cin>>pt[0][i];
    }
    cout<<"enter processing time for l2"<<endl;
    for(int i=0;i<n;i++){
        cin>>pt[1][i];
    }
    cout<<"enter transfer time from l1 to l2"<<endl;
    for(int i=0;i<n-1;i++){
        cin>>tt[0][i];
    }
    cout<<"enter transfer time from l2 to l1"<<endl;
    for(int i=0;i<n-1;i++){
        cin>>tt[1][i];
    }
    cout<<"enter exit time for l1,l2"<<endl;
    cin>>x[0]>>x[1];
    int p1=e[0]+pt[0][0];
    int p2=e[1]+pt[1][0];

    for(int i=1;i<n;i++){
        int newp1=min(p1+pt[0][i], p2+tt[1][i-1]+pt[0][i]);
        int newp2=min(p2+pt[1][i], p1+tt[0][i-1]+pt[1][i]);
        p1=newp1;
        p2=newp2;
    }
    cout<<"min p time: "<<min(p1+x[0],p2+x[1])<<endl;
    return 0;
}
