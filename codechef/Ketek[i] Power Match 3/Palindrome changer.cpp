#include<iostream>

using namespace std;

bool palindromChecker(int* arr, int N){
    for(int i = 0; i <= N/2; i++){
        if(arr[i] != arr[N-i-1])
            return false;
    }
    return true;
}

int* convertBigNumberToArray(int* arr, string str, int n){
    for(int i = 0; i < n; i++)
        arr[i] = str[i]-'0';
    return arr;
}

// void display(int* arr, int n){
//     for(int i = 0;i < n; i++)
//         cout << arr[i] << " ";
//     cout << endl;
// }

int main(){
    int T, N, tCases;
    int res;
    int* arr;
    int pos, val;
    string str;
    cin >> T;
    while(T--){
        cin >> N;
        cin >> str;
        cin >> tCases;
        arr = new int[N];
        arr = convertBigNumberToArray(arr, str, N);
        // display(arr, N);
        while(tCases--){
            cin >> pos >> val;
            arr[pos] = val; // change the value;
            // display(arr, N);
            res = palindromChecker(arr, N);
            if(res)
                cout << "Palindrome" << endl;
            else
                cout << -1 << endl;
        }
        delete arr;
    }
}