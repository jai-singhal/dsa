// https://cses.fi/problemset/task/1621

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int findPiv(const vector<int>arr, int l, int r){
    int mid;
    int n = arr.size();
    if(arr[n-1] > arr[0])
        return -1;
    while(l <= r){
        mid = l+(r-l)/2;
        if(mid - 1 >= 0 && 
            arr[mid - 1] > arr[0] && mid + 1 < n && arr[mid-1] > arr[mid + 1])
            return mid;
        if(arr[mid] > arr[0] )
            l = mid;
        else if(arr[mid] < arr[0])
            r = mid;
    }
    return -1;
}

int binarySearch(const vector<int>arr, int l, int r, int key){
    int mid;
    int n = arr.size();
    while(l <= r){
        mid = l+(r-l)/2;
        if(arr[mid] == key)
            return mid;
        if(arr[mid] < key)
            l = mid+1;
        else if(arr[mid] > key)
            r = mid-1;
    }
    return -1;
}

int search(const vector<int> &A, int B) {
    int pivIndex = findPiv(A, 0, A.size()-1);
    if(pivIndex != -1){
        if(A[0] <= B){
            return binarySearch(A, 0, pivIndex - 1, B);
        }
        else{
            return binarySearch(A, pivIndex, A.size()-1, B);
        }
    }
    else{
        return binarySearch(A, 0, A.size()-1, B);
    }
    return -1;
}

int main(){
    vector<int> arr = { 1, 7, 67, 133, 178};
    cout << arr.size() << endl; 
    int B =  1;
    cout << search(arr, B);
}

