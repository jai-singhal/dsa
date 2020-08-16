// https://www.interviewbit.com/problems/wave-array/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

vector<int> wave(vector<int> &A) {
    sort(A.begin(), A.end());
    int n = A.size();
    vector<int> solution;
    int i = 1;
    while(i < n){
        solution.push_back(A[i]);
        solution.push_back(A[i-1]);
        i = i + 2;
    }
    if(n%2) solution.push_back(A[n-1]);
        
    return solution;
}
