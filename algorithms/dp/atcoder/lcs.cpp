#include<iostream>
#define max(a, b) a>b?a:b
using namespace std;

string lcs(string s1, string s2){
    string cs1 = "";
    string cs2 = "";

    const int N = s1.size();
    const int M = s2.size();
    int dp[N+1][M+1];

    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= M; j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;

            else if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else if(s1[i-1] != s2[j-1])
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int i = N, j = M;
    while (i > 0 && j > 0){
        if(s1[i-1] == s2[j-1]){
            cs1 = s1[i-1] + cs1;
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }

    // cout << dp[N][M] << endl;
    // cout << cs1 << endl << cs2 << endl;
    return cs1;
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    cout << lcs(s2, s1);
    return 0;
}