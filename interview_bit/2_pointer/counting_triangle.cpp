// https://www.interviewbit.com/problems/3-sum-zero/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define MODVAL 1000000007

int exponentSearch(vector<int> A, int start, int end, int key){
    int factor = 1;
    while(start <= end){
        if(A[start] > key){
            start += factor;
            factor++;
        }
        else if(A[start] < key){
            start -= factor;
            factor = 1;
        }
    }
    return start;
}

int nTriang(vector<int> &A) {
    sort(A.begin(), A.end());
    int len = A.size();
    int totalSol = 0;
    for(int i = 0; i < len; i++){
        for(int j = i+1; j < len; j++){
            int third = exponentSearch(A, j+1, len - 1, A[i] + A[j]);
            cout << third << endl;
            if(A[i] == A[j] && A[i] == A[third])
                totalSol += (third - j)%MODVAL;
            else if(third > j){
                totalSol += (third - j - 1)%MODVAL;
            }
        }
    }
    return totalSol;
    
}

int main(){
    vector<int> v = {1, 1, 1, 2, 2};
    cout << nTriang(v);
}
