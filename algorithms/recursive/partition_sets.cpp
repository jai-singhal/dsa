/*
Print equal sum sets of array (Partition problem)
Given an array arr[]. 
Determine whether it is possible to split the array into two sets such that the sum of elements 
in both the sets is equal. If it is possible, then print both the sets. If it is not possible 
then output -1.

Examples :
Input : arr = {2, 7, 11, 9, 4}
Output : Set 1 = {2, 9}, 
         Set 2 = {11}
         Set 3 = {7, 4}
Sum all of the sets is 11 and equal.

Input : arr = {1, 5, 3}
Output : -1
No partitioning results in equal sum sets.
*/

#include <iostream>
using namespace std;

void find_subset_util(int* set, int l, int r, int total_subset, int sum, int subset_sum, int* subset){
    if(subset_sum > sum/total_subset)
        return;

    if(subset_sum == sum/total_subset){
        for(int i = 0; i <= r; i++)
            if (subset[i])
                cout << subset[i] << " ";
        cout << endl;
        return;
    }

    if(l > r)
        return;

    for(int i = l; i <= r; i++){
        subset[i] = set[i]; // put the value
        find_subset_util(set, i+1, r, total_subset, sum, subset_sum + set[i], subset);
        subset[i] = 0; //erase the value if not allowed
    }
}

int find_subset(int* set, int n, int total_subset){
    int sum = 0;
    int subset_sum = 0;
    int* subset = (int*)malloc(n*sizeof(int));

    for(int i = 0; i < n; i++)
        sum+=set[i];

    if(sum % total_subset != 0){
        cout << "No subset possible" << endl;
        return -1;
    }

    find_subset_util(set, 0, n-1, total_subset, sum, subset_sum, subset);
    return 0;
}

int main(int argc, char const *argv[]){

    int set[] = {2, 7, 11, 9, 4};
    int n = sizeof(set)/sizeof(int);
    int total_subset = 3;
    find_subset(set, n, total_subset);
    return 0;
}

