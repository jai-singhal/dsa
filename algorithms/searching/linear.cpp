#include<iostream>
using namespace std;

int linearSearch(int* arr, int n, int key){
    for(int i = 0; i < n; i++){
        if(arr[i] == key){
            cout << "Key found at index: " << i << endl;
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1, 13, 25, 38, 6, 18, 19, 9};
    int n = sizeof(arr)/sizeof(int);
    int res = linearSearch(arr, n, 38);
    if(res == -1)
        cout << "Key not found" << endl;
}