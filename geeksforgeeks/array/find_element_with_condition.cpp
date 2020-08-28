/*Element with left side smaller and right side greater-*/
/*https://practice.geeksforgeeks.org/problems/unsorted-array/0*/

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int T, N, val;
    cin >> T;
    int index, j, k;
    vector<int> arr;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> val;
            arr.push_back(val);
        }
        index = floor(N/2);
        j = index-1;
        while(j >= 0){
            while(arr[j] <= arr[index] && j >= 0){
                j--;
            }
            if(j == -1) break;
            if(arr[j] > arr[index] && index < N-1)
                index++;
        }
        k = index+1;
        while(k < N){
            while(arr[k] >= arr[index] && k < N)
                k++;
            if(k == N) break;
        }
        if(j == -1 && k == N && index != N-1)
            cout << arr[index] << endl;
        else
            cout << -1 << endl;
        arr.clear();
    }
    return 0;
}