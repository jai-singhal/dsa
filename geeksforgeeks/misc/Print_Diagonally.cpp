#include<iostream>
using namespace std;
int main(void) {
    int T, N;
    // cin >> T;
    T = 1;
    while(T--){
        // cin >> N;
        N = 3;
        int arr[N][N] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
        };

        int i = 0, k = 0, j, m = 0, x = 0;
        while(m < N){
            while(k < N){
                i = m;
                j = k;
                while(i <= k){
                    cout << arr[i][j];
                    i++;
                    j--;
                }
                k++;
            }
            k--;
            m++;
        }

    }
	return 0;
}