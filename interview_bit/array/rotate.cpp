#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

void solution(vector<vector<int>> &arr){
    int n = arr.size();
    int val;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i; j++){
            val = arr[n-j-1][i];
            arr[n-j-1][i] = arr[j][n-i-1];
            arr[j][n-i-1] = val;
        }
    }
}

int main(){
    vector<vector<int>> arr = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    solution(arr);

    int n = arr.size();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

}