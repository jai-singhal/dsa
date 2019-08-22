/*
Find the longest path in a matrix with given constraints
https://www.geeksforgeeks.org/find-the-longest-path-in-a-matrix-with-given-constraints/
*/

#include<iostream>
#include<cmath>
using namespace std;

int main(int argc, char const *argv[]){
    int matrix[3][3] = {{1, 2, 9},
                   {5, 3, 8},
                   {4, 6, 7}};

    int N = 3;

    int dp[N+1][N+1] = {0};
    int max_out = 0;
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else{
                dp[i][j] = 1;
                if(
                abs(matrix[i-2][j-1] - matrix[i-1][j-1]) == 1 &&
                abs(matrix[i-1][j-2] - matrix[i-1][j-1]) == 1){
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + 2;
                }
                else if(abs(matrix[i-2][j-1] - matrix[i-1][j-1]) == 1){
                    dp[i][j] = dp[i-1][j] + 1;
                }
                else if(abs(matrix[i-1][j-2] - matrix[i-1][j-1]) == 1){
                    dp[i][j] = dp[i][j-1] + 1;
                }
            }
            if(dp[i][j] > max_out)
                max_out = dp[i][j];
        }
    }

    cout << max_out << endl;

    return 0;
}
