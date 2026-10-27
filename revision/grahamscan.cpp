#include<bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

Point p0;

int cross(Point a, Point b, Point c) {
    return (b.x-a.x)*(c.y-a.y) -
           (b.y-a.y)*(c.x-a.x);
}

int dist(Point a, Point b) {
    return (a.x-b.x)*(a.x-b.x) +
           (a.y-b.y)*(a.y-b.y);
}

bool cmp(Point a, Point b) {
    int c = cross(p0, a, b);

    if(c == 0)
        return dist(p0, a) < dist(p0, b);

    return c > 0;
}

int main() {
    int n;
    cin >> n;

    Point p[100];

    for(int i = 0; i < n; i++)
        cin >> p[i].x >> p[i].y;

    int low = 0;

    for(int i = 1; i < n; i++) {
        if(p[i].y < p[low].y ||
          (p[i].y == p[low].y && p[i].x < p[low].x))
            low = i;
    }

    swap(p[0], p[low]);
    p0 = p[0];

    sort(p + 1, p + n, cmp);

    Point st[100];
    int top = 0;

    for(int i = 0; i < n; i++) {
        while(top >= 2 &&
              cross(st[top-2], st[top-1], p[i]) <= 0)
            top--;

        st[top++] = p[i];
    }

    for(int i = 0; i < top; i++)
        cout << st[i].x << " " << st[i].y << endl;

    return 0;
}