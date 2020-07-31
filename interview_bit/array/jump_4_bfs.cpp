    // https://leetcode.com/problems/jump-game-iv/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<unordered_map>

using namespace std;

int minJumps(vector<int>& arr) {
    queue<pair<int, int>> q;
    unordered_map<int, vector<int>> mp;
    for(int i = 0; i < arr.size(); i++)
        mp[arr[i]].push_back(i);
        
    int n = arr.size();
    vector<int> vis(n, false);
    q.push({ n - 1, 0 });
    vis[n - 1] = 1;
    int steps = 0;
    while(!q.empty()) {
        int sz = q.size();
        int f = q.front().first;
        int steps = q.front().second;
        q.pop();
        if(f == 0)
            return steps;
        if(f - 1 >= 0 && !vis[f - 1]) {
            q.push({ f - 1, steps + 1 });
            vis[f - 1] = true;
        }
        if(f + 1 < n && !vis[f + 1]) {
            q.push({ f + 1, steps + 1 });
            vis[f + 1] = true;
        }
        for(auto j : mp[arr[f]]) {
            if(j == f)
                continue;
            if(!vis[j]) {
                vis[j] = true;
                q.push({ j, steps + 1 });
            }
        }
    }
    return -1; 

}