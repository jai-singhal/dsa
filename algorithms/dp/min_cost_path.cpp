/* https://www.geeksforgeeks.org/maximum-sum-path-in-a-matrix/*/

#include<iostream>
#include<vector>
using namespace std;

int min(int a, int b){
    if(a<b) return a;
    else return b;
}

int minCostClimbingStairs(vector<int>& cost) {
    int N = cost.size();
    if(N <= 2)
        return cost[N-1];
        
    int dp[N+1];
    dp[0] = cost[0];
    dp[1] = cost[1];

    for(int i = 2; i <= N; i++){
        if (i < N)
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        else
            dp[i] = min(dp[i-1], dp[i-2]);
    }
    return dp[N];
}

int main(){
    vector<int>cost;
    int N, numb;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> numb;
        cost.push_back(numb);
    }
    cout << minCostClimbingStairs(cost);
    return 0;
}