//1. Minimum Operations
#include<iostream>
using namespace std;

int main(){
    int T,N, countOperations;
    cin >> T;
    while (T--){
        cin >> N;
        countOperations = 0;
        while(N!=0){
            if(N%2 == 0){
                N = N/2;
            }
            else{
                N = N-1;
            }
            countOperations++;
        }
        cout << countOperations << endl;
    }
    
    return 0;
}