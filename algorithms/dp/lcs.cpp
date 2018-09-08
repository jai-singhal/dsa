#include<iostream>
#include <chrono> 
#include <cstring>
#define max(a, b) a>b?a:b

using namespace std;
using namespace std::chrono;

/* 
Problem Statement:Given two strings, find longest common subsequence
/*

Method 1: Using Brute force method
i/p: string x, y and their respective lengths
o/p: length of longes common subsequence
T.C: O(2^(m+n))         (T(n) = T(n-1) + T(m-1))
S.C: O(m+n)
*/
int lcs(const char* x, const char* y, int m, int n){
    if(m == 0 || n == 0){
        return 0;
    }
    if(x[m-1] == y[n-1])
        return 1 + lcs(x, y, m-1, n-1);
    else
        return max(
                lcs(x, y, m-1, n),
                lcs(x, y, m, n-1)
            ); 
}


/*
Method 2: Using Dynamic Programming
i/p: string x, y and their respective lengths
o/p: length of longes common subsequence
T.C: O(m*n)
S.C: O(m*n)
*/
int lcsDP(const char* x, const char* y, int m, int n){
    int table[m+1][n+1];

    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            if(i == 0 || j == 0)
                table[i][j] = 0;
            else if(x[i-1] == y[j-1])
                table[i][j] = 1+table[i-1][j-1];
            else
                table[i][j] = max(table[i-1][j], table[i][j-1]);
        }
    }
    return table[m][n];
}



// driver function
int main(int argc, char const *argv[]){
    auto duration = 0;
    int res;
    const char* x = "BAYABAXUPTXY";
    const char* y = "BABXABAXPXUXY";

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    res = lcs(x, y, strlen(x), strlen(y));

    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>( t2 - t1 ).count();

    cout << "Using Brute force method: " << res << endl;
    cout << "Executed in time: " << duration << " nano sec" << endl;

    cout << endl << endl;


    /*DP EXECUTION */
    high_resolution_clock::time_point t3 = high_resolution_clock::now();

    res = lcsDP(x, y, strlen(x), strlen(y));

    high_resolution_clock::time_point t4 = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>( t4 - t3 ).count();

    cout << "Using Dynamic programming method: " << res << endl;
    cout << "Executed in time: " << duration << " nanosec" << endl;


    return 0;
}
