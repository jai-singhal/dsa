#include <iostream>
#include <algorithm>
using namespace std;

struct Item{
    int val;
    int wt;
};

bool cmp(Item a, Item b){
    double r1 = (double)(a.val/a.wt);
    double r2 = (double)(b.val/b.wt);
    return r1>r2;
}

double fractionalKnapsack(int W, Item arr[], int n){
    Item temp;
    int currWt = 0;
    double currVal = 0.00;
    double remain; 

    sort(arr, arr+n, cmp);
    
    for(int i = 0; i < n; i++){
        if(W >= arr[i].wt + currWt){
            currVal += arr[i].val;
            currWt += arr[i].wt;
        }
        else{
            remain = (double)(W - currWt)/arr[i].wt;
            currVal += (arr[i].val)*remain;
            break;
        }
    }
    return currVal;
};

int main(){
    Item arr[] = {{100, 20}, {120, 30}, {60, 10}};
    int n = sizeof(arr)/sizeof(Item);
    int W = 50;

    cout << "Knapsack profit: " << fractionalKnapsack(W, arr, n);
    return 0;
}