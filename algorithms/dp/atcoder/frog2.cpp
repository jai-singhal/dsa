#include<iostream>
#include<cmath>
#include <vector>
#include <algorithm> 

using namespace std;

int min(int x, int y){
    if(x<y)
        return x;
    return y;
}

int frog1_soln(int* arr, int N, int K){
    vector<vector<int>> dp;
    vector<int> temp;
    temp.push_back(0);
    dp.push_back(temp);
    int i = 1;

    while(i < N){
        cout << i << endl;
        vector<int> temp;
        for(int m = i-1; m <= i - min(i, K); m--){
            for(int j = 0; j < dp[m].size(); j++)
                temp.push_back(abs(arr[i] - arr[m]) + dp[m][j]);
            dp.push_back(temp);
        }
        for(int j = 0; j < dp[i].size(); j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;

        i += 1;
    }
    return *min_element(dp.back().begin(), dp.back().end());
}

int main(){
    int N, K;
    cin >> N >> K;
    int* arr = new int[N];
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    cout << frog1_soln(arr, N, K);
    delete arr;
}