#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<set>
#include<vector>

using namespace std;

int diffPossible(const vector<int> &A, int B) {
    set<int> diff;
    int asize = A.size();
    for(int i = 0; i < asize; i++){
        if(diff.find(A[i]) == diff.end()){
            diff.insert(A[i]+B);
            diff.insert(A[i]-B);
        }
        else{
            return 1;
        }
    }
    return 0;
}