#include<iostream>
#include<cmath>
#include <vector>
using namespace std;

int min(int x, int y){
    if(x<y)
        return x;
    return y;
}

int frog1_soln(int* arr, int N){
    vector<int> dp_1, dp_2, temp;
    dp_2.push_back(0);
    dp_1.push_back(abs(arr[1] - arr[0]));
    int diff1, diff2;
    int i = 2;
    while(i < N){
        diff1 = abs(arr[i] - arr[i-1]);
        diff2 = abs(arr[i] - arr[i-2]);
        
        temp.assign(dp_2.begin(), dp_2.end());
        dp_2.assign(dp_1.begin(), dp_1.end());

        for(int m = 0; m < 2; m++){
            dp_1[m] += diff1;
        }
        for(int m = 0; m < 2; m++){
            dp_1[m] = min(dp_1[m], temp[m] + diff2);
        }
        i++;
    }
    return min(dp_1[0], dp_1[0]);
}

int main(){
    int N;
    cin >> N;
    int* arr = new int[N];
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    cout << frog1_soln(arr, N);
    delete arr;
}