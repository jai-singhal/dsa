/*Like Binary Search, Jump Search is a searching algorithm for SORTED arrays. 
The basic idea is to check fewer elements (than linear search) by jumping ahead by fixed steps or
 skipping some elements in place of searching all elements.*/

/*Therefore, the best step size is m = √n.*/

 /* Refer https://www.geeksforgeeks.org/jump-search/ */

#include<iostream>
#include<cmath>
using namespace std;

int jumpSearch(int* arr, int n, int key){
    int step = (int)sqrt(n);
    int i = 0;
    while(arr[min(i, n-1)] < key)
        i += step;

    while(arr[i] >= key && i >= 0)
        i--;

    if(arr[i+1] == key)
        return (i+1);
    else    
        return -1;
}
int main(){
    int arr[] = {-5, 0, 0, 1, 1, 2, 2, 3, 5, 8, 13, 15, 21, 34, 55, 89, 144, 233, 377, 610, 615};
    int n = sizeof(arr)/sizeof(int);
    int res = jumpSearch(arr, n, 2);
    if(res == -1)
        cout << "Key not found" << endl;
    else   
        cout << "Key found at index: "<< res << endl;
}