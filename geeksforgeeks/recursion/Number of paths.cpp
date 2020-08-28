#include<iostream>
using namespace std;

int NumberOfPaths(int i, int j, int m, int n){
    if(i >= m || j >= n)
        return 0;
    return 1 + NumberOfPaths(i+1, j, m, n) + 
        NumberOfPaths(i, j+1, m, n);
}

int main(){
    const char matrix[3][3] = {
        {'A', 'B', 'C'},
        {'D', 'E', 'F'},
        {'G', 'H', 'I'}
    };
    cout << NumberOfPaths(3, 3, 0, 0) << endl;
}