#include<iostream>
#include <chrono> 
#include <vector>
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
vector<int> sum_of_subsets(int arr[], int n, int sum, vector<int> sub_arr){

    if(sum <= 0)
        return sub_arr;
    if(n == 0){
        return sub_arr;
    }
    if(arr[n-1] > sum)
        return sum_of_subsets(arr, n-1, sum, sub_arr);

    if(sum - arr[n-1] >= 0)
        sub_arr.push_back(arr[n-1]);

    for(int i = 0; i < sub_arr.size(); i++)
        cout << sub_arr[i] << " ";
    cout << endl;

    cout << "C1: sum_of_subsets(" << n-1 << ", " << sum-arr[n-1] << ")" << endl;
    sum_of_subsets(arr, n-1, sum-arr[n-1], sub_arr);


    cout << "C2: sum_of_subsets(" << n-1 << ", " << sum << ")" << endl;
    sum_of_subsets(arr, n-1, sum, sub_arr);
    return sub_arr;
}


/*
Method 2: Using Dynamic Programming
i/p: weight[], profit[], knapsack capacity
o/p: max profit
T.C: O(m*n)
S.C: O(m*n)
*/



// driver function
int main(int argc, char const *argv[]){
    auto duration = 0;
    vector<int> subset;
    int arr[] = {20, 70, 50, 30, 100, 25, 45, 60};
    int sum = 100;


    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    subset = sum_of_subsets(arr, sizeof(arr)/sizeof(int), 100, subset);

    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>( t2 - t1 ).count();

    cout << "Using Brute force method: " << endl;
    for(int i = 0; i < subset.size(); i++){
        cout << subset[i] << " ";
    }
    cout << endl;

    cout << "Executed in time: " << duration << " nanosec" << endl;

    cout << endl << endl;


    // /*DP EXECUTION */
    // high_resolution_clock::time_point t3 = high_resolution_clock::now();

    // res = knapsackDP(weights, profits, m, n);

    // high_resolution_clock::time_point t4 = high_resolution_clock::now();
    // duration = duration_cast<nanoseconds>( t4 - t3 ).count();

    // cout << "Using Dynamic programming method: " << res << endl;
    // cout << "Executed in time: " << duration << " nanosec" << endl;


    return 0;
}
