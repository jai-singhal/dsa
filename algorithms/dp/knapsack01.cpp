#include<iostream>
#include <chrono> 
#include <cstring>
#define max(a, b) a>b?a:b

using namespace std;
using namespace std::chrono;

/* 
Problem Statement:Given Weight, Profit array, and Knapsack capacity, find max profit
/*

Method 1: Using Brute force method
i/p: weight[], profit[], knapsack capacity
o/p: max profit
T.C: O(2^n)
S.C: O(n)
*/
int knapsack(const int* weights, const int* profits, int capacity, int n){
    if(capacity == 0 || n == 0)
        return 0;
    else if (weights[n-1] > capacity)
        return knapsack(weights, profits, capacity, n-1);
    else 
        return max(
            profits[n-1] + knapsack(weights, profits, capacity - weights[n-1], n-1),
            knapsack(weights, profits, capacity, n-1)
        );
}


/*
Method 2: Using Dynamic Programming
i/p: weight[], profit[], knapsack capacity
o/p: max profit
T.C: O(m*n)
S.C: O(m*n)
*/

int knapsackDP(const int* weights, const int* profits, int capacity, int n){
    int table[n+1][capacity+1];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= capacity; j++){
            if(i == 0 || j == 0)
                table[i][j] = 0;
            else if (weights[i-1] > j)
                table[i][j] = table[i-1][j];
            else
                table[i][j] =  max(
                                profits[i-1] + table[i - 1][j - weights[i-1]], 
                                table[i-1][j]
                            );
        }
    }
    return table[n][capacity];
}



// driver function
int main(int argc, char const *argv[]){
    auto duration = 0;
    int res;
    const int profits[] =  {25, 70, 30, 40, 50};
    const int weights[] =  {5, 3, 4, 3, 4};
    int n = 5, m = 13;

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    res = knapsack(weights, profits, m, n);

    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>( t2 - t1 ).count();

    cout << "Using Brute force method: " << res << endl;
    cout << "Executed in time: " << duration << " nanosec" << endl;

    cout << endl << endl;


    /*DP EXECUTION */
    high_resolution_clock::time_point t3 = high_resolution_clock::now();

    res = knapsackDP(weights, profits, m, n);

    high_resolution_clock::time_point t4 = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>( t4 - t3 ).count();

    cout << "Using Dynamic programming method: " << res << endl;
    cout << "Executed in time: " << duration << " nanosec" << endl;


    return 0;
}
