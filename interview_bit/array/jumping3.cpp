// https://leetcode.com/problems/jump-game-iii/
#include<iostream>
#include<vector>
#include<stack>

using namespace std;
bool canReach(vector<int>& arr, int start) {
    int len = arr.size();
    vector<bool>vistied(len, false);
    stack<int> to_visit;
    to_visit.push(start);
    
    while(!to_visit.empty()){
        if(arr[start] == 0)
            return true;
        start = to_visit.top();
        to_visit.pop();

        if(!vistied[start]){
            if(start - arr[start] >= 0){
                if( vistied[ start - arr[start] ] == false )
                    to_visit.push(start - arr[start]);
            }
            if(arr[start] + start < len){
                if(vistied[start + arr[start]] == false)
                    to_visit.push(start + arr[start]);
            }
        }
        
        vistied[start] = true;
    }
    return false;
}

int main(){
    vector<int> v = {3,2,1,0,4};
        // 2,0,6,9,8,4,5,0,8,9,1,2,9,6,8,8,0,6,3,1,2,2,1,2,6,5,3,1,2,2,6,4,2,4,3,0,0,0,3,8,2,4,0,1,2,0,1,4,6,5,8,0,7,9,3,4,6,6,5,8,9,3,4,3,7,0,4,9,0,9,8,4,3,0,7,7,1,9,1,9,4,9,0,1,9,5,7,7,1,5,8,2,8,2,6,8,2,2,7,5,1,7,9,6};
    cout << canJump(v);
}