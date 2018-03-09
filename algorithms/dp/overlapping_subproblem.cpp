#include<iostream>
#define MAX 100
#define NILL -1
using namespace std;

/*
MEMORIZATION METHOD (TOP DOWN)
FIBBONNACCI EXAMPLE
*/
int fibUtil(int n, int* lookup){
    if(lookup[n] == NILL){
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        lookup[n] = fibUtil(n-1, lookup) + fibUtil(n-2, lookup);
    }
    return lookup[n];
}

int fib(int n){
    int lookup[MAX];
    for(int i = 0; i < MAX; i++)
        lookup[i] = NILL;

    return fibUtil(n, lookup);
}


/*
TABULATION (BOTTOM UP)
FIBBONNACCI EXAMPLE
*/


int fibMem(int n){
    int fib[n+1];
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i <= n; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib[n];
}


int main(void){
    cout << "Fib by MEMORIZATION: " << fib(40) << endl;
    cout << "Fib by TABULATION: " << fibMem(40) << endl;
    return 0;
}