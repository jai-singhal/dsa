#include <iostream>
#include <vector>
using namespace std;
 int gcd(int a, int b) { // a > b
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
 void fun(int n, int r, vector<int> arr, int prod, int* max_prod){
    if(n == 0 && prod > *max_prod){
        *max_prod = prod;
        for(int i = 0; i < arr.size(); i++)
            cout << arr[i] << " ";
        cout << endl;
    }
     if(gcd(r, prod) != 1 || r > n)
        return;

    for(int i = r; i <= n; i++){
        if(r != 0){
            arr.push_back(r);
            prod = prod*r;
        }
        fun(n-r, i+1, arr, prod, max_prod);
        if(r != 0){
            prod = prod/r;
            arr.pop_back();
        }
    }
}
 int main(int argc, char const *argv[]){
    int n = 5;
    vector <int> arr;
    int* max_prod;
    *max_prod = 1;
    fun(n, 0, arr, 1, max_prod);
    cout << *max_prod << endl;
    return 0;
}
