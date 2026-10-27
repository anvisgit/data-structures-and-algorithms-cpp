#include<bits/stdc++.h>
using namespace std; 
struct Point{
int x,y;};

Point p0;
int cross(Point a, Point b, Point c){
  return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);}
bool cmp(Point a, Point b){
  return cross(p0, a,b)>0;}
int main(){
  int n;
  cin>>n;
  vector<Point> p(n);
  for(int i=0;i<n;i++){
    cin>>p[i].x>>p[i].y;
  }
  // find the pivot element
  int k=0;
  for(int i=0;i<n;i++){
    if(p[i].y<p[k].y ||(p[i].y==p[k].y && p[i].x<p[k].y)){
      k=i;
    }
  }
  //pivot at index0
  swap(p[0], p[k]);
  p0=p[0];
  //sort based on polar angle 
  sort(p.begin()+1, p.end(), cmp);
  //init stack
  vector<Point> st;
  //push in stack if cross>0(left) else its right => pop
  for(int i=0;i<n;i++){
    Point pt=p[i];
    while(st.size()>=2 && cross(st[st.size()-2], st[st.size()-1, pt)<=0){
      st.pop_back();
    }
    st.push_back(pt);
  }
  //print stack
  for(int i=0;i<n;i++){
    cout<<st[i].x<<" "<<st[i].y<<endl;
  }
  return 0;
}

      
