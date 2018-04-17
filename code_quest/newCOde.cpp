#include <iostream>
#include<cmath>
using namespace std;

int computeFunctionUtil(int l, int step, int n){
    if(n == 1){
        return l;
    }
    if(n % 2 == 0)
        return computeFunctionUtil(l, step+1, n/2);
    else
        return computeFunctionUtil(l + pow(2, step), step+1, (n-1)/2);   
}

int computeFun(int n){
    int win = computeFunctionUtil(1, 1, n);
    cout << "For n = " << n << " Winner is: " << win << endl;
    return win;
}

int main(){
    computeFun(4120682);  // == 4047061

    return 0;
}