#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int w, p;
    double r;
};

bool cmp(Item a, Item b) {
    return a.r > b.r;
}

// Calculate upper bound
double bound(Item a[], int n, int i, int w, int p, int cap) {
    double profit = p;

    while (i < n && w + a[i].w <= cap) {
        w += a[i].w;
        profit += a[i].p;
        i++;
    }

    // Take fraction of next item
    if (i < n)
        profit += (cap - w) * a[i].r;

    return profit;
}

void knapsack(Item a[], int n, int i, int w, int p, int cap, int &best) {

    // Invalid node
    if (w > cap)
        return;

    // Update best profit
    if (p > best)
        best = p;

    // All items processed
    if (i == n)
        return;

    // Prune if this node cannot beat best
    if (bound(a, n, i, w, p, cap) <= best)
        return;

    // Include current item
    knapsack(a, n, i + 1,
             w + a[i].w,
             p + a[i].p,
             cap, best);

    // Exclude current item
    knapsack(a, n, i + 1,
             w, p, cap, best);
}

int main() {
    int n, cap;
    cin >> n >> cap;

    Item a[100];

    // Input items
    for (int i = 0; i < n; i++) {
        cin >> a[i].w >> a[i].p;
        a[i].r = (double)a[i].p / a[i].w;
    }

    // Sort by profit/weight ratio
    sort(a, a + n, cmp);

    int best = 0;

    // Start Branch and Bound
    knapsack(a, n, 0, 0, 0, cap, best);

    cout << best;
}
