#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> arr, int l, int r, int key){
    int mid = l + (r-l)/2;
    while(l <= r){
        mid = l + (r-l)/2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            l = mid+1;
        else if(arr[mid] > key)
            r = mid-1;
    }
    return -1;
}

int find_piviot(vector<int> arr, int low, int high){
    if(low > high)
        return -1;
    if(high == low)
        return low;
    int mid = low + (high-low)/2;
    if(mid < high && arr[mid] > arr[mid+1])
        return mid;
    if(mid > low && arr[mid-1] > arr[mid])
        return mid-1;
    if(arr[low] >= arr[mid])
        return find_piviot(arr, low, mid-1);
    return find_piviot(arr, mid+1, high);
}

int find_element(vector<int> arr, int n, int key){
    int piv = find_piviot(arr, 0, n);
    cout << "Piviot: " << piv << endl;
    if(piv == -1)
        return -1;
    if(arr[0] > key)
        return binary_search(arr, piv + 1, n, key);
    else
        return binary_search(arr, 0, piv, key);
    return -1;
}

int main(){
    vector<int> arr = {8, 9, 10, 11, 12, 13, 15, 18, 3, 4, 5, 6, 7};
    int n = arr.size();
    cout << find_element(arr, n, 2);
    return 0;
}