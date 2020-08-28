// Problem Statement:
// https://www.geeksforgeeks.org/partition-set-k-subsets-equal-sum/
/*
Partition of a set into K subsets with equal sum

Given an integer array of N elements, the task is to divide this array into K non-empty subsets 
such that the sum of elements in every subset is same. 

All elements of this array should be part of exactly one partition.
*/

#include <iostream>
using namespace std;

bool partitionKEqualSumSubsetUtil(int* arr, int n, int k, int maxSubsetSum, int sumTill, int i, int* visited){
    static int kx = 1;
    cout << i << " " << sumTill << endl;
    for(int m = 0; m < n; m++)
        cout << visited[m] << " ";
    cout << endl << endl;

    if(kx == k+1)
        return true;

    if(sumTill == maxSubsetSum){
        cout << "Soln obtained" << endl;
        kx++;        
    }

    if(sumTill + arr[i] > maxSubsetSum){
        return false;
    }

    visited[i] = kx;    
    partitionKEqualSumSubsetUtil(arr, n, k, maxSubsetSum, sumTill + arr[i], i+1, visited);    
    
    visited[i] = 0;
    partitionKEqualSumSubsetUtil(arr, n, k, maxSubsetSum, sumTill, i+1, visited);    
    
}

bool partitionKEqualSumSubset(int* arr, int n, int k){
    int sum = 0;
    int visited[n];
    for(int i = 0; i < n; i++){
        sum += arr[i];
        visited[i] = 0;
    }
    return partitionKEqualSumSubsetUtil(arr, n, k, sum/k, 0, 0, visited);
}

int main(){
    int arr[] = {2, 1, 5, 5, 6};
    int n = sizeof(arr)/sizeof(int);
    int k = 3;
    partitionKEqualSumSubset(arr, n, k);
}