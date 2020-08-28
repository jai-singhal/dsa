// https://www.interviewbit.com/problems/diffk/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
int removeElement(vector<int> &A, int B) {
    int n = A.size();
    // vector<int> to_delete;
    // for(int i = 0; i < n; i++){
    //     if(A[i] == B){
    //         A.erase(A.begin() + i);
    //     }
    // }

    // return A.size();
    int i = 0, j = 0;
    while(j < n){
        while(j < n && A[j] != B)
            j++;
            
        if(j >= n-1)
            break; 

        i = j+1;

        while(i < n && A[i] == B){
            i++;
        }
        if(i > n-1)
            break;
        swap(A[i], A[j]);

        j++;
    }
    i = 0;
    for(auto a: A){
        if(a != B)
            i++;
    }

    // cout << i << " " << j << endl;
    A.erase(A.begin() + i, A.end());
    return A.size();
    
}

int main(){
    vector<int> A = {2, 0, 1, 2, 0, 3, 2, 2, 2, 1, 0, 0, 0, 1, 0, 0, 2, 2, 2, 3, 2, 3, 1, 2, 1, 2, 2, 3, 2, 3, 0, 3, 0, 2, 1, 2, 0, 0, 3, 2, 3, 0, 3, 0, 2, 3, 2, 2, 3, 1, 3, 3, 0, 3, 3, 0, 3, 3, 2, 0, 0, 0, 0, 1, 3, 0, 3, 1, 3, 1, 0, 2, 3, 3, 3, 2, 3, 3, 2, 2, 3, 3, 3, 1, 3, 2, 1, 0, 0, 0, 1, 0, 3, 2, 1, 0, 2, 3, 0, 2, 1, 1, 3, 2, 0, 1, 1, 3, 3, 0, 1, 2, 1, 2, 2, 3, 1, 1, 3, 0, 2, 2, 2, 2, 1, 0, 2, 2, 2, 1, 3, 1, 3, 1, 1, 0, 2, 2, 0, 2, 3, 0, 1, 2, 1, 1, 3, 0, 2, 3, 2, 3, 2, 0, 2, 2, 3, 2, 2, 0, 2, 1, 3, 0, 2, 0, 2, 1, 3, 1, 1, 0, 0, 3, 0, 1, 2, 2, 1, 2, 0, 1, 0, 0, 0, 1, 1, 0, 3, 2, 3, 0, 1, 3, 0, 0, 1, 0, 1, 0, 0, 0, 0, 3, 2, 2, 0, 0, 1, 2, 0, 3, 0, 3, 3, 3, 0, 3, 3, 1, 0, 1, 2, 1, 0, 0, 2, 3, 1, 1, 3, 2};

    int b = 2;
    for(auto a: A){
        if(a != b)
            cout << a << " ";
    }
    cout<< endl;
    cout << A.size() << endl;
    
    cout << removeElement(A, b) << endl;
    for(auto a: A){
        cout << a << " ";
    }
    cout << endl;
}
