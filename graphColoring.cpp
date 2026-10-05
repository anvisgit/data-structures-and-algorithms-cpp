#inlude<iostream>
using namespace std;
// n = number of vertices
// m = number of  colors
// graph[i][j] = 1 if vertex i and j are connected
// color[i] → color assigned to vertex i
// 0 → vertex has no color yet
bool isSafe(int v, int g[10][10], int color[],int c,int n){
  for (int i = 0; i < n; i++) {
        if (g[v][i] == 1 && color[i] == c) //connected and coloured 
            return false;
  }
  return true;
}
bool soln(int v, int g[10][10], int color[], int n, int m){
  if (v==n)
    return true;
  for(int i=0;i<n;i++){
    if(isSafe(v,g,color,i,n)
      color[v]=c;
      if(soln(v+1,g,color,n,m))
        return true;
      color[v]=0;
  }
}
int main() {
    int n, m;
    int graph[10][10];
    int color[10] = {0};
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of colors: ";
    cin >> m;
    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    if (solve(0, graph, color, n, m)) {

        // Display colors
        cout << "\nSolution:\n";
        for (int i = 0; i < n; i++)
            cout << "Vertex " << i << " -> Color " << color[i] << endl;
    }
    else {
        cout << "No solution";
    }

    return 0;
}
