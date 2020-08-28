
x
#include<iostream>
#include<vector>
#include<cmath>


using namespace std;

int min_(int a, int b){
        if(a<=b) return a;
        return b;
    }
    
bool isPerfectSquare(long double x) {   
    long double sr = sqrt(x); 
    return ((sr - floor(sr)) == 0); 
} 

int numSquares(int n) {
    int dp[n+1];
    int i, j;
    for(i = 1; i <= n; i++){
        if(isPerfectSquare(i))
            dp[i] = 1;
        else
            dp[i] = i;
    }
    
    for(i = 2; i <= n; i++){
        for(j = floor(sqrt(i)); j >= 1; j--){
            dp[i] = min_(dp[i], dp[i-j*j] + dp[j*j]);
        }
    }
    // for(i = 1; i <= n; i++){
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    return dp[n];
}

int main(){
    int N;
    cin >> N;
    cout << numSquares(N);
}