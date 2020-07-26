https://leetcode.com/problems/jump-game-i/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool canJump(vector<int> nums) {
    int len = nums.size();
    if(len == 1)
        return true;
    vector<int> validMoves(len, false);
    
    for(int i = len-2; i >= 0; i--){
        
        if(nums[i] != 0 && nums[i] + i >= len-1)
            validMoves[i] = true;
        else{
            for(int j = i; j <= nums[i] + i && j < len; j++){
                if(validMoves[j] == true){
                    validMoves[i] = true;
                    break;
                }
            }
        }
    }

    return validMoves[0];
}

int main(){
    vector<int> v = {3,2,1,0,4};
        // 2,0,6,9,8,4,5,0,8,9,1,2,9,6,8,8,0,6,3,1,2,2,1,2,6,5,3,1,2,2,6,4,2,4,3,0,0,0,3,8,2,4,0,1,2,0,1,4,6,5,8,0,7,9,3,4,6,6,5,8,9,3,4,3,7,0,4,9,0,9,8,4,3,0,7,7,1,9,1,9,4,9,0,1,9,5,7,7,1,5,8,2,8,2,6,8,2,2,7,5,1,7,9,6};
    cout << canJump(v);
}