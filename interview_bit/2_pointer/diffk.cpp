// https://www.interviewbit.com/problems/diffk/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int binarySearch(vector<int> arr, int l, int r, int key){
    int mid;
    while(l <= r){
        mid = l + (r-l)/2;
        if(arr[mid] == key)
            return mid;
        if(arr[mid] < key)
            l = mid+1;
        else
            r = mid-1;
    }
    return -1;
}

int diffPossible(vector<int> &A, int B) {
    int n = A.size();
    // int max_ = A[n-1];
    // for(int i = 0; i < n; i++){
    //     if(B+A[i] <= max_){
    //         int mid = binarySearch(A, i+1, n-1, B+A[i]);
    //         if(mid != -1)
    //             return 1;
    //     }
    // }
    // return 0;
    
    // solution: 2 
    int i = 0, j = 1;
    while(i < n && j < n){
        if(i != j && A[j] - A[i] == B)
            return 1;
        if(A[j] - A[i] < B)
            j++;
        else
            i++;
    }
    return 0;
}
