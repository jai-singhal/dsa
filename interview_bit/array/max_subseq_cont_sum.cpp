// https://www.interviewbit.com/problems/max-sum-contiguous-subarray/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
int maxSubArray(const vector<int> &A) {
    int n = A.size();
    vector<int> dp(n);
    dp[0] = A[0];
    for(int i = 1; i < n; i++){
        if(dp[i-1] + A[i] > A[i]){
            dp[i] = dp[i-1] + A[i];
        }
        else{
            dp[i] = A[i];
        }
    }
    return *max_element(dp.begin(), dp.end());
}