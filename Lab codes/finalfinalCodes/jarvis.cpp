#include<bits/stdc++.h>
using namespace std;
struct Point{
int x,y;};
int cross(Point a, Point b, Point c){
    return (b.x-a.x)*(c.y-a.y)- ( b.y-a.y)*(c.x-a.x);
}

int main()
  int n;
  cin>>n;
  vector<Point> p(n);
  for(int i=0;i<n;i++){
    cin>>p[i].x>>p[i].y;
  }
  if(n<3){
    for(int i=0;i<n;i++){
      cout<<p[i].x<<" "<<p[i].y<<endl;
      return 0;
    }
  }
  int l=0;
  for(int i=0;i<n;i++){
    if(p[i].x<p[l].x){
      l=i;
    }
  }

vector <Point> hull;
int cur=l;
do{
hull.push_back(cur);
int q=(cur+1)%n;
for(int i=0;i<n;i++){
  if(cross(p[curr], p[q], [i])<0)
    q=i
  }
  cur=q;
}
  while(cur!=1);
//prinr hull
return 0;
}



  
