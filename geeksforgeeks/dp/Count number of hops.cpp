/*
Count number of hops
https://practice.geeksforgeeks.org/problems/count-number-of-hops/0
*/

#include<iostream>
using namespace std;

int calculateHopsRecursive(int N){
    if(N < 0)
        return 0;
    if(N == 0)
        return 1;

    return calculateHopsRecursive(N-1) +
            calculateHopsRecursive(N-2) +
            calculateHopsRecursive(N-3);
}

int calculateHopsDP(int N){
    int f0 = 1, f1 = 1, f2 = 2;
    int temp;
    if(N == 0 || N == 1)
        return 1;
    for(int i = 2; i < N; i++){
        temp = f0;
        f0 = f1;
        f1 = f2;
        f2 = temp + f0 + f1; 
    }
    return f2;
}


int main(){
    int T, N;
    cin >> T;
    while(T--){
        cin >> N;
        cout << calculateHopsDP(N) << endl;        
    }

}
