// https://leetcode.com/problems/2-keys-keyboard/


#include<iostream>
#include<vector>

using namespace std;

int min_(int a, int b){
    if(a<=b) return a;
    return b;
}

int Solution(int n){
    int i, j;
    int dp[n+1];
    dp[1] = 0;
    
    for(int i = 2; i <= n; i++)
        dp[i] = i;
    
    for(i = 2; i <= n; i++){
        j = 2;
        while(j*i <= n){
            dp[j*i] = min_(dp[j*i], dp[i] + j);
            j += 1;
        }
    }
    return dp[n]; 
}


int main(){
    int N;
    cin >> N;
    cout << Solution(N);
}