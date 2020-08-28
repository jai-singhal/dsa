#include<iostream>
#include<vector>
#define PRII pair<int, int> 
using namespace std;

void bfs(int x, int y, vector<vector<int>>G, int radius){
    vector<PRII> queue;
    vector<PRII> visited;

    visited.push_back(PRII(x, y));
    queue.push_back(PRII(x, y));
    int range = 0;
    while(!queue.empty() && range < radius){
        PRII top = queue.back();
        queue.pop_back();
        range += 1;
        G[top.first][top.second] = 1;
        if(G[top.first + 1][top.second])
        queue.push_back(PRII(top.first + 1, top.second));
        queue.push_back(PRII(top.first - 1, top.second));
        queue.push_back(PRII(top.first, top.second + 1));
        queue.push_back(PRII(top.first, top.second - 1));

    }
} 

string solve(const int A, const int B, int C, int D, vector<int> &E, vector<int> &F) {
    vector<vector<int>>(A, vector<int>(B, 0));


}