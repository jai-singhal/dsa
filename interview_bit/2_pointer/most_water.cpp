// https://www.interviewbit.com/problems/container-with-most-water/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define PA pair<int, int>

int maxArea(vector<int> &A) {
    
    int len = A.size();
    int start = 0, end = len - 1;
    int maxArea = 0;
    while(start < end){
        int area = (end-start)*min(A[start], A[end]);
        if(maxArea < area)
            maxArea = area;
            
        if(A[start] < A[end]){
            start++;
        }
        else if(A[start] > A[end]){
            end --;
        }
        else{
            start++;
            end--;
        }
        
    }

    return maxArea;
}

int main(){
    vector<int> v = {1};
    cout << maxArea(v) << endl;

}