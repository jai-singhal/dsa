// https://www.interviewbit.com/problems/merge-overlapping-intervals/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

//  Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
 

bool comparator(Interval a, Interval b){
    return a.start < b.start;
}
 
vector<Interval> merge(vector<Interval> &A) {
    sort(A.begin(), A.end(), comparator);
    int asize = A.size();
    vector<Interval> solution;
    if(asize == 0)
        return solution;
        
    solution.push_back(A[0]);
    for(int i = 1; i < asize; i++){
        Interval top = solution.back();
        if(top.end < A[i].start){
           solution.push_back(A[i]);
        }
        else if(top.end < A[i].end){
          top.end = max(top.end, A[i].end);
          top.start = min(top.start, A[i].start);
          solution.pop_back();
          solution.push_back(top);
        }
    }
    return solution;
}