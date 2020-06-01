#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int T, N, M;
    cin >> T;
    while(T--){
        cin >> N >> M;
        int* arr_n = new int[N];
        int* arr_m = new int[M];
        vector<int> not_present;
        unordered_map<int, int> order;

        for(int i = 0; i < N; i++)
            cin >> arr_n[i];
            
        for(int i = 0; i < M; i++){
            cin >> arr_m[i];
            order.insert(make_pair(arr_m[i], 0));
        }

        for(int i = 0; i < N; i++){
            if (order.find(arr_n[i]) == order.end()){
                // not present
                not_present.push_back(arr_n[i]);
            }
            else{
                order.at(arr_n[i])++;
                //present
            }
        }
        
        for(int i = 0; i < M; i++){
            for(int j = 0; j < order.at(arr_m[i]); j++){
                cout << arr_m[i] << " ";
            }
        }
        sort(not_present.begin(), not_present.end()); 
        
        for(auto &i: not_present){
            cout << i << " ";
        }
        cout << endl;

        delete[] arr_m;
        delete[] arr_n;
    }
    return 0;
}