    // https://leetcode.com/problems/jump-game-iv/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<unordered_map>

using namespace std;

int minJumps(vector<int>& arr) {
    unordered_map<int, vector<int>> same;
    int len = arr.size();
    for(int i = 0; i < len; i++){
        if(same.find(arr[i]) == same.end()){
            // npt found
            vector<int> x = {i,};
            same.insert({arr[i], x});
        }
        else{
            same.find(arr[i])->second.push_back(i);
        }
    }

    vector<bool>vistied(len, false);
    vector<int>steps(len, 0);

    for(int i = 0; i < len; i++)    steps[i] = i;

    queue<int> to_visit;

    int start = 0;
    to_visit.push(start);
    
    while(!to_visit.empty()){
        start = to_visit.front();
        to_visit.pop();
        if(!vistied[start]){
            
            if(start + 1 < len){
                steps[start+1] = min(steps[start+1], steps[start] + 1);
                to_visit.push(start + 1);
            }

            if(same.find(arr[start])->second.size() > 1){
                for(auto s: same.find(arr[start])->second){
                    if(s!=start){
                        steps[s] = min(steps[s], steps[start] + 1);
                        to_visit.push(s);
                    }
                }
            }
            if(start - 1 >= 0){
                steps[start-1] = min(steps[start-1], steps[start] + 1);
                to_visit.push(start - 1);
            }

        }
        vistied[start] = true;
    }
    return steps[len-1];
}

int main(){
    vector<int> v = {68,-94,-44,-18,-1,18,-87,29,-6,-87,-27,37,-57,7,18,68,-59,29,7,53,-27,-59,18,-1,18,-18,-59,-1,-18,-84,-20,7,7,-87,-18,-84,-20,-27};
    cout << minJumps(v);
}
// [-76,3,66,-32,64,2,-19,-8,-5,-93,80,-5,-76,-78,64,2,16]
// Out: 8, expected: 5