// https://www.interviewbit.com/problems/longest-consecutive-sequence/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int longestConsecutive(const vector<int> &A) {
    set<int> arr;
    int maxCount = 0;
    for(auto a: A){
        arr.insert(a);
    }
    for(auto a: A){
        if(arr.find(a+1) == arr.end()){
            int ele = a-1;
            int count = 1;
            while(arr.find(ele) != arr.end()){
                ele--;
                count++;
            }
            maxCount = max(maxCount, count);
        }
    }
    return maxCount;
}