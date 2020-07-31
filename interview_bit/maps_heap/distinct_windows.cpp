// https://www.interviewbit.com/problems/distinct-numbers-in-window/
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

vector<int> dNums(vector<int> &A, int B) {
    unordered_map<int, int> map;
    vector<int> solutions;
    int n = A.size();
    int i = 0, start = 0;

    while(i < B){
        if(map.find(A[i]) == map.end())
            map[A[i]] = 1;
        else
            map[A[i]]++;
        i++;
    }

    while(i <= n){
        
        solutions.push_back(map.size());
        if(map[A[start]] == 1)
            map.erase(map.find(A[start]));
        else
           map[A[start]]--; 

        if(map.find(A[i]) == map.end())
            map[A[i]] = 1;
        else
            map[A[i]]++;

        i++;
        start++;
    }
    return solutions;
}

int main(){
    vector<int> v = {1, 1, 2, 2};
    vector<int> sol;
    sol = dNums(v, 1);
    for(auto i: sol)
        cout << i << " ";
    cout << endl;
    return 0;
}