#include<bits/stdc++.h>
using namespace std;

struct Point{
  int x,y };
Point p0; // stores the lowest point + used as pivot
int cross(Point a, Point b, Point c){
  return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);}
bool cmp(Point a, Point b){
  return cross(p0,a,b)>0;}

int main(){
  int n;
  cin>>n;
  vector<Point>p(n);
  for(int i=0;i<n;i++){
    cin>>p[i].x>>p[i].y;
  }
  int k=0; //stores the index of the lowest point
  for(int i=1;i<n;i++){
    if(p[i].y<p[k].y || p[i].y==p[k].y && p[i].x<p[k].x){
      k=i;
    }
  }
  swap(p[0], p[k]); //place pivot at 0th index 
  p0=p[0] ;
  //sort the remoaining points w angle comparision
  sort(p.begin()+1, p.end(), cmp);

  vector <Point> st;
  for( int i=0;i<p.size();i++){
    Point pt=p[i];
  
    while (st.size()>=2&& cross(st[st.size()-2], st[st.size()-1], pt)<=0) {
      st.pop_back();
    }
    st.push_back(pt);
  }
  for(int i=0;i<st.size();i++){
    cout<<st[i].x<<" "<<st[i].y<<endl;
  }
  return 0;
}
