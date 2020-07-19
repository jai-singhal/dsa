/* https://www.geeksforgeeks.org/maximum-sum-path-in-a-matrix/*/

#include<iostream>
#include<vector>

using namespace std;

int max_sum_path(int N, int M){
    int i, j;
    int dp[N+1][M+1];
    for(i = 0; i <= N; i++){
        for(j = 0; j <= M; j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else
                cin >> dp[i][j];
        }
    }

    for(i = 1; i <= N; i++){
        for(j = 1; j <= M; j++){
            if(
                dp[i][j-1] > dp[i-1][j] &&
                dp[i][j-1] > dp[i-1][j-1] )
                    dp[i][j] += dp[i][j-1];
            else if(
                dp[i-1][j-1] > dp[i][j-1] &&
                dp[i-1][j-1] > dp[i-1][j] )
                    dp[i][j] += dp[i-1][j-1];
            else if(
                dp[i-1][j] > dp[i][j-1] &&
                dp[i-1][j] > dp[i-1][j-1] )
                    dp[i][j] += dp[i-1][j];
        }
    }

    for(i = 0; i <= N; i++){
        for(j = 0; j <= M; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }

    return dp[N][M];
}

int minPathSum(vector<vector<int>>& grid) {
    int N = grid.size();
    int M = grid[0].size();
    int i, j;
    int dp[N+1][M+1];
    
    for(i = 0; i <= N; i++){
        for(j = 0; j <= M; j++){
            if(i == 0 || j == 0)
                dp[i][j] = INT32_MAX;
            else
                dp[i][j] = grid[i-1][j-1];
            // cout << dp[i][j] << " ";
        }
        // cout << endl;
    }


    for(i = 1; i <= N; i++){
        for(j = 1; j <= M; j++){
            if(dp[i][j-1] < dp[i-1][j])
                dp[i][j] += dp[i][j-1];
            else if(dp[i-1][j] < dp[i][j-1])
                dp[i][j] += dp[i-1][j];
            else if(dp[i-1][j] == dp[i][j-1] && dp[i][j-1] != INT32_MAX)
                dp[i][j] += dp[i-1][j];
        }
    }


    return dp[N][M];
}

int main(){
    int N, M;
    // cin >> N >> M;
    vector<vector<int>> grid = {
            {0, 1},
            {1, 0}
    };

    cout << minPathSum(grid);
}

/*

2 3
100 -350 -200
-100 -300 700

4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

3 3 
500 100 230
1000 300 100
200 1000 200

*/