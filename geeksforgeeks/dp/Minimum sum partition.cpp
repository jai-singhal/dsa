// Minimum sum partition
// https://practice.geeksforgeeks.org/problems/minimum-sum-partition/0
#include<iostream>
#include<cmath>
#define MAXINF 999999
using namespace std;

int minSumPartitionDP(int* arr, int N){
    int dp[N][N];
    int lastDiff = 0;
    int minSum = MAXINF;
    for(int i = 0; i < N; i++){
        lastDiff = arr[i];
        for(int j = 0; j < N; j++){
            if(i == j){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = abs(lastDiff - arr[j]);
                lastDiff = dp[i][j];
            }
        }
        if(minSum > lastDiff){
            minSum = lastDiff;
        }
    }
    return minSum;
}


int main(){
    int T, N;
    cin >> T;
    while(T--){
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++)
            cin >> arr[i];
        cout << minSumPartitionDP(arr, N) << endl;
    }  
    return 0;  
}