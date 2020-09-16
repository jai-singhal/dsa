   /* C++ Program to find LCA of n1 and n2 using one traversal of Binary Tree */
#include <iostream> 
#include <vector> 
#include <algorithm> 


using namespace std; 

int solve(string A, string B) {
    int n = A.size(), m = B.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
                continue;
            }
            if(A[i-1] == B[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[n][m];
}

int main(){
    string a = "bebdeeedaddecebbbbbabebedc";
    string b = "abaaddaabbedeedeacbcdcaaed";
    cout << solve(a, b);
}