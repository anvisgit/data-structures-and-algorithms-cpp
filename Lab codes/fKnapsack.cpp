#include<iostream>
#include<algorithm>
using namespace std;

struct Items{
    int value;
    int wt;
};

bool compare(Items a, Items b){
    double r1 = (double)a.value / a.wt;
    double r2 = (double)b.value / b.wt;
    return r1 > r2;
}

double fKnapsack(Items arr[], int n, int c){
    sort(arr, arr + n, compare);

    double valin = 0.0;

    for(int i = 0; i < n; i++){
        if(arr[i].wt <= c){
            valin += arr[i].value;
            c -= arr[i].wt;
        }
        else{
            valin += ((double)arr[i].value / arr[i].wt) * c;
            break;
        }
    }

    return valin;
}

int main(){
    int n, c;

    cout << "Enter number of items: ";
    cin >> n;

    Items arr[n];

    cout << "Enter value and weight:\n";
    for(int i = 0; i < n; i++){
        cin >> arr[i].value >> arr[i].wt;
    }

    cout << "Enter capacity: ";
    cin >> c;

    cout << "Maximum Value: " << fKnapsack(arr, n, c) << endl;

    return 0;
}
