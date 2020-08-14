#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int firstMissingPositive(vector<int> A) {
    int n = A.size();
    for(int i = 0; i < n; i++){
        if(A[i] <= 0 || A[i] > n)
            continue;
            
        if(A[i] != i+1){
            // if both element are same.
            if(A[i] == A[A[i]-1])
                continue;
            swap(A[i], A[A[i]-1]);
            i--; //check again if it is at correct pos. 
        }
    }

    for(int i = 0; i < n; i++){
        if(A[i] != i+1) return i+1;
    }
    return n+1;
}


int firstMissingPositiveAproach1(vector<int> &A){
    int n = A.size();
    int max_ = *max_element(A.begin(), A.end());
    if(max_ < 0)
        max_= n+5;

    max_ += 100;

    vector<int> is_there(max_, false);
    
    for(int i = 0; i < n; i++){
        if(A[i] > 0 && A[i] <= n)
            is_there[A[i]] = true;
    }

    int soln = 1;
    for(int i = 1; i < max_; i++){
        if(!is_there[i]){
            soln = i;
            break;            
        }

    }
    return soln;
}


int main(){
    int n, val;
    cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++){
        cin >> val;
        arr.push_back(val);
    }

    cout << firstMissingPositive(arr) << endl;
    return 0;
}