// https://atcoder.jp/contests/dp/tasks/dp_i
#include<iostream>
#include<cmath>
#include <vector>
#include <iomanip>      // std::setprecision

using namespace std;

class coin{
    public:
        int head;
        int tail;
    coin(int h, int t){
        head = h;
        tail = t;
    }
};

double coin_soln(double* arr, int N){
    vector<pair<double, coin>> sols;
    vector<pair<double, coin>> curr_sols;

    sols.push_back(pair<double, coin>(arr[0], coin(1, 0)));
    sols.push_back(pair<double, coin>(1-arr[0], coin(0, 1)));

    for(int i = 1; i < N; i++){
        curr_sols.erase(curr_sols.begin(), curr_sols.end());
        curr_sols = sols;
        sols.erase(sols.begin(), sols.end());
        
        // for(auto j:curr_sols){
        //     cout << j.first << ": " << j.second.head << " " << j.second.tail << " ";
        // }
        // cout << endl;
        
        for(auto j:curr_sols){
            sols.push_back(
                pair<double, coin>(
                    j.first*arr[i],
                    coin(j.second.head + 1, j.second.tail)
                )
            );
            sols.push_back(
                pair<double, coin>(
                    j.first*(1-arr[i]),
                    coin(j.second.head, j.second.tail + 1)
                )
            );
        }        
    }
    double total = 0.0;
    for(auto j:sols){
        if(j.second.head > j.second.tail)
            total += j.first;
    }   
    return total;
}

int main(){
    int N;
    cin >> N;
    double* arr = new double[N];
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    cout << setprecision(10) << coin_soln(arr, N);
    delete arr;
}