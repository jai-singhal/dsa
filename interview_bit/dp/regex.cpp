// https://www.interviewbit.com/problems/regular-expression-match/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int isMatch(const string A, const string B) {
    int i = 0, j = 0;
    int la = A.length(), lb = B.length();

    vector<vector<bool>> dp(la + 1, vector<bool>(lb + 1, false));
    dp[0][0] = true;
    
    for(j = 1; j <= lb; j++){
        if(B[j-1] == '*')
            dp[0][j] = dp[0][j-1];

    for(i = 1; i <= la; i++){
        for(j = 1; j <= lb; j++){
            if(A[i-1] == '?' || B[j] == '?' && (i==j))
                dp[i][j] = true;
            else if(A[i] == '*' || B[j] == '*')
                dp[i][j] = true;
            else if(A[i] == B[j] && (i==j || la-i == lb-j))
                dp[i][j] = true;
            else
                dp[i][j] = false;
        }
    }

    for(i = 0; i < la; i++){
        for(j = 0; j < lb; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
}

int main(){
    // const string A = "aabbaaabbbaa", B = "a*bbb*aaa";
    const string A = "cc", B = "?";

    cout << isMatch(A, B);
}