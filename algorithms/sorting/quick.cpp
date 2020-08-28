#include<iostream>
using namespace std;

void swap(int& a, int& b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int partition(int* arr, int l, int r){
    int i = l-1;
    int piv = arr[r];
    for(int j = l; j < r; j++){
        if(piv >= arr[j]){
            i++;            
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[r]);
    return (i+1);
}

void quickSort(int* arr, int l, int r){
    if(l >= r)
        return;

    int piv = partition(arr, l, r);
    quickSort(arr, 0, piv-1);
    quickSort(arr, piv+1, r);
}

int main(){

    int arr[] = {81, 40, 55, 10, 9, 33, 65};
    int n = sizeof(arr)/sizeof(int);
    quickSort(arr, 0, n-1);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}