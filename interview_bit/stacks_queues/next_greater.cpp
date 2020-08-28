#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextGreater(vector<int> arr){
    stack<pair<int, int>> s;
    int n = arr.size();
    vector<int> solution(n, 0);
    s.push(pair<int, int>(0, arr[0]));
    
    for(int i = 1; i < n; i++){
        if(s.top().second > arr[i]){
            s.push(pair<int, int>(i, arr[i]));
            continue;
        }
        while(!s.empty() && arr[i]  > s.top().second){
            solution[s.top().first] = arr[i];
            s.pop();
        }
        s.push(pair<int, int>(i, arr[i]));
    }
    while(!s.empty()){
        solution[s.top().first] = -1;
        s.pop();
    }
    return solution;
}

int main(){
    vector<int> v = {5, 3, 2, 10, 6, 8, 1, 4, 12, 7, 4};
    vector<int> sol = nextGreater(v);
    for(auto i: sol){
        cout << i << " ";
    }
    return 0;
}