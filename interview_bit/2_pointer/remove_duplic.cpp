// https://www.interviewbit.com/problems/add-two-numbers-as-lists/
#include<iostream>
#include<vector>

using namespace std;

int removeDuplicates(vector<int> &A) {
    int len = A.size();

    int pointerA = 0, pointerB = 1, pointerC = 2;
    if(len <= 2)
        return len;

    vector<int> sameIndex, B;

    for(int i = 0; i < len; i++){
        if(A[pointerA] == A[pointerB] && A[pointerB] == A[pointerC]){
        }
        else{
            B.push_back(A[i]);
        }
        pointerA++;
        pointerB++;
        pointerC++;
    }
    A = B;
    return A.size();
}

int main(){
    vector<int> v = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
    cout << removeDuplicates(v) << endl;
    for(auto i: v)
        cout << i << " ";
}