// https://www.interviewbit.com/problems/add-two-numbers-as-lists/
#include<iostream>
#include<vector>

using namespace std;

int removeDuplicates(vector<int> &A) {
    int len = A.size();

    int pointerA = 0, pointerB = 1;

    int count = 0;
    for(int i = 0; i < len; i++){
        if(A[pointerA] != A[pointerB]){ 
            A[count++] = A[i];    
        }
        pointerA++;
        pointerB++;
    }
    A.erase(A.begin() + count, A.end());
    return A.size();
}

int main(){
    vector<int> v = { 1, 1};
    cout << removeDuplicates(v) << endl;
    for(auto i: v)
        cout << i << " ";
}