// https://atcoder.jp/contests/dp/tasks/dp_h
#include<iostream>
#define max(a, b) a>b?a:b
#define MOD 1000000007
using namespace std;

int hgrid(const int m, const int n){
    int grid[m+1][n+1];
    char inp;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin>>inp;
            if(inp == '.')
                grid[i][j] = 0;
            else if(inp == '#')
                grid[i][j] = -1;
        }
    }

    grid[0][0] = 1;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 && j ==0)
                continue;
            if(grid[i][j] != -1){
                if(grid[i-1][j] != -1 && i > 0)
                    grid[i][j] = (grid[i][j] + grid[i-1][j]) % MOD;
                if(grid[i][j-1] != -1 && j > 0)
                    grid[i][j] = (grid[i][j] + grid[i][j-1]) % MOD;
            }
        }
    }
    return grid[m-1][n-1];
}

int main(){
    int M, N;
    cin >> M >> N;
    cout << hgrid(M, N);
    return 0;
}