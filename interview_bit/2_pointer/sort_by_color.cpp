// https://www.interviewbit.com/problems/sort-by-color/

#include<iostream>
#include<vector>
#include<unordered_map>


using namespace std;

void sortColors(vector<int> &A) {
    unordered_map<int, int> colors_count;
    colors_count.insert({0, 0});
    colors_count.insert({1, 0});
    colors_count.insert({2, 0});
    for(auto i:A){
        colors_count[i]++;
    }
    A.erase(A.begin(), A.end());
    for(int i = 0; i < 3; i++){
        auto c = colors_count.find(i);
        int count = c->second;
        while(count--){
            A.push_back(c->first);
        }
    }
}
