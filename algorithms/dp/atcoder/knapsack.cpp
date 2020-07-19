#include<iostream>
#include <cmath>
using namespace std;

long int max(long int x, long int y){
    if(x<y)
        return y;
    return x;
}

int main(){
    long int N, W;
    cin >> N >> W;
    long int wt[N];
    long int val[N];

    for(long int i = 0; i < N; i++){
        cin >> wt[i] >> val[i];
    }
    long int dp[N+1][W+1];

    for (long int i = 0; i <= N; i++){
        for(long int j = 0; j <= W; j++){
            if (i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if (wt[i-1] <= j){
                dp[i][j] = max(
                    val[i-1] + dp[i-1][j-wt[i-1]],
                    dp[i-1][j]
                );
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }

        
    cout << dp[N][W] << endl;
}