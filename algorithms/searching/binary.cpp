#include<iostream>
using namespace std;

int binarySearch(int* arr, int l, int r, int key){
    int mid = l+(r-l)/2;
    if(l > r)
        return -1;

    if(arr[mid] == key){
        cout << "key found at index: " << mid << endl;
        return mid;
    }
        
    if (arr[mid] < key)
        binarySearch(arr, mid+1, r, key);
    else if(arr[mid] > key)
        binarySearch(arr, l, mid-1, key);
}

int main(){

    int arr[] = {1, 6, 9, 13, 18, 19, 25, 38};
    int n = sizeof(arr)/sizeof(int);
    int res = binarySearch(arr, 0, n-1, 38);
    if(res == -1)
        cout << "Key not found" << endl;
}