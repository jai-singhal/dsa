#include <iostream>
using namespace std;

int main(){
    int T, N, SUM;
    int low, high, sumObtain;
    int* arr;
    cin >> T;
    while(T--){
        cin >> N >> SUM;
        arr = new int[N];
        sumObtain = low = high = 0;

        for(int i = 0; i < N; i++)
            cin >> arr[i];
        
        while(low < N){
            while(sumObtain < SUM){
                sumObtain += arr[high];
                high++;
            }
            if(sumObtain == SUM)
                break;
            else if(sumObtain > SUM){
                sumObtain -= arr[low];
                low += 1;
            }
        }
        if(low == N)
            cout << -1 << endl;
        else
            cout << low + 1 << " " << high << endl;

        delete arr;
    }
    return 0;
}
