#include<iostream>
using namespace std;

int main(){
    int T, N;
    cin >> T;
    while(T--){
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++)
            cin >> arr[i];
        int start = 0, end = N-1;
        int sumLeft = 0, sumRight = 0;
        while(start < end){
            sumLeft += arr[start++];
            sumRight += arr[end--]; 
            while(sumLeft < sumRight)
                sumLeft += arr[start++];
            while(sumLeft > sumRight)
                sumRight += arr[end--];
        }
        if(start == end && sumLeft == sumRight)
            cout << start+1 << endl;
        else
            cout << -1 << endl;
    }

}