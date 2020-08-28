#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int arr[10] = {3, 30, 34, 5, 9};
    int temp, factor, swap_temp;
    int N = 5;

    for(int i = 0; i <= 10; i++){
        factor = pow(10, i);
        temp = 0;
        for(int j = 1; j < N; j++){
            if(arr[j]%factor > arr[temp]%factor){
                swap_temp = arr[j];
                arr[j] = arr[temp];
                arr[temp] = swap_temp;
                temp++;
            }
        }

    }

    return 0;
}