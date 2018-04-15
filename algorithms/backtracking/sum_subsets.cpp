#include <iostream>
using namespace std;

void sumOfSubsetsUtil(int* arr, int sum_till, int sum_left, int sum_req, int i, int n, bool* elementState){
    if(i > n)   //base conditions
        return;

    if(sum_till == sum_req){    // Got the soln
        cout << "Sum obtained by choosing: ";
        for(int j = 0; j < n; j++)
            if(elementState[j])
                cout << arr[j] << " ";
        cout << endl;
        return;
    }
    if(sum_till + arr[i] > sum_left+sum_till) //base conditions
        return;

    //take ith element
    elementState[i] = true;
    sumOfSubsetsUtil(arr, sum_till + arr[i], sum_left - arr[i], sum_req, i+1, n, elementState);
    
    sum_left += arr[i]; //backtrack
    elementState[i] = false;  //backtrack
    
    // do not take ith element
    sumOfSubsetsUtil(arr, sum_till, sum_left - arr[i], sum_req, i+1, n, elementState);
}

void sumOfSubsets(int* arr, int n, int sum){
    int totalSum = 0;
    bool elementState[n];
    cout << "Elements are: ";
    for(int i = 0; i < n; i++){
        totalSum += arr[i];
        elementState[i] = false;
        cout << arr[i] << " ";
    }
    cout << endl << endl;
    sumOfSubsetsUtil(arr, 0, totalSum, sum, 0, n, elementState);
}

int main(){
    int arr[] = {15, 22, 14, 26, 32, 9, 16, 8};
    int n = sizeof(arr)/sizeof(int);
    int target = 53;
    sumOfSubsets(arr, n, target);
    return 0;
}