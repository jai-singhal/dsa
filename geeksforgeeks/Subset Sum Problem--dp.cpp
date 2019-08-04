/*https://practice.geeksforgeeks.org/problems/subset-sum-problem/0 */

#include<iostream>
using namespace std;

/* Tarika 1 */
bool subsetSumRecUtil(int* arr, int sum1, int sum2, int N){
    if(sum1 == sum2 && sum1 != 0 && sum2 != 0 && N == 0)
        return true;
    if(N == 0)
        return false;

    if (subsetSumRecUtil(arr + 1, sum1 + arr[0], sum2, N-1))
        return true;

    if ((sum1 != 0 || sum2 != 0) && subsetSumRecUtil(arr + 1, sum1, sum2 + arr[0], N-1))
        return true;
    return false;
}

string subsetSumRec(int* arr, int N){
    bool result = subsetSumRecUtil(arr, 0, 0, N);
    if(result == 0)
        return "NO";
    else
        return "YES";
}

/* ----------------------------------------------------------------- */
/*Tarika #2 */
bool subsetSumTarika2(int* arr, int N, int sumReq){
    if(sumReq < 0 || N == 0)
        return false;
    if(sumReq == 0)
        return true;
    if (subsetSumTarika2(arr + 1,  N-1, sumReq - arr[0]))
        return true;
    if (subsetSumTarika2(arr + 1,  N-1, sumReq))
        return true;
    return false;
}

int sumofArray(int* arr, int N){
    int sum = 0;
    for(int i = 0; i < N; i++)
        sum += arr[i];
    return sum;
}
/*------------------------------------------------------------------- */
/*Drtiver function */
int main(int argc, char const *argv[]){
    int *arr;
    int N, T;
    cin >> T;
    while(T--){
        cin >> N;
        arr = new int[N];
        for(int i = 0; i < N; i++)
            cin >> arr[i];
        int sum = sumofArray(arr, N);
        if(sum % 2 == 0)
            if(subsetSumTarika2(arr, N, sum/2))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        else
            cout << "NO" << endl;
       delete arr;
    }
    return 0;
}
