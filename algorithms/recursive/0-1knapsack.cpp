#include<iostream>
# define max(a,b) a>b ? a : b;
using namespace std;

int knapsack(int W, int val[], int wt[], int n){
    if(n == 0 || W == 0) //BASE CASE
        return 0;    
    if(wt[n-1] > W)
        return knapsack(W, val, wt, n-1);
    else
        return max(val[n-1] + knapsack(W-wt[n-1], val, wt, n-1 ), knapsack(W, val, wt, n-1 ));
}

int main(){
    int wt[] = {20, 30, 10};
    int val[] = {100, 120, 60};
    int n = 3;
    int W = 50;
    cout <<  "Knapsack profit: " << knapsack(W, val, wt, n);
    return 0;
}