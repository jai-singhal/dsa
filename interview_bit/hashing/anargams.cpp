
#include<iostream>
#include<map>
#include<vector>

using namespace std;

vector<vector<int>> anagrams(const vector<string> &A) {
    map<string, int> anargams;
    vector<vector<int>> solution;
    int i = 1;
    int solsize = 0;
    for(auto a: A){
        sort(a.begin(), a.end());
        if(anargams.find(a) == anargams.end()){
            vector<int> sol;
            sol.push_back(i);
            // int alen = a.length();
            anargams.insert({a, solsize});
            solution.push_back(sol);
            solsize++;
        }
        else{
            solution[anargams[a]].push_back(i);
        }
        i++;
    }

    
    return solution;
    
}
