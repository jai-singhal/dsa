#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>

using namespace std;

void fourSum(vector<int> &A, int target) {
    
    unordered_map<int, pair<int, int>> mymap;
    vector<vector<int>> solutions; 
    int n = A.size();
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++)
            mymap.insert({
                A[i] + A[j], pair<int, int>(i, j)
            });
    }

    
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int sum = A[i] + A[j];  
            if(mymap.find(target - sum) != mymap.end()){
                // found
                pair<int, int> mypair = mymap.find(target - sum)->second;
                
                if(mypair.first != i && mypair.second != j){
                    vector<int>sol;
                    sol.push_back(i);
                    sol.push_back(j);
                    sol.push_back(mypair.first);
                    sol.push_back(mypair.second);
                    sort(sol.begin(), sol.end());
                    // cout << solstr << " " << pvs_string << endl;
    
                    solutions.push_back(sol);

                }
            }
            else
                mymap.insert({
                    A[i] + A[j], pair<int, int>(i, j)
                });
        }
    }

    sort(solutions.begin(), solutions.end());
    vector<int> pvs_sol(4, 0);
    vector<vector<int>> solutions_unique; 

    for(int i = 0; i < solutions.size(); i++){
        for(int j = 0; j < solutions[i].size(); i++){
            if(pvs_sol != solutions[i])
                solutions_unique.push_back(solutions[i]);
            pvs_sol = solutions[i];
        }
    }

    for(auto solution: solutions_unique){
        for(auto sol:solution){
            cout << sol << " ";
        }
        cout << endl;
    }
    // return solutions;
}

int main(){
    vector<int> arr = { 4, 7, -4, 2, 2, 2, 3, -5, -3, 9, -4, 9, -7, 7, -1, 9, 9, 4, 1, -4, -2, 3, -3, -5, 4, -7, 7, 9, -4, 4, -8};

    int target=-3;
    fourSum(arr, target);
}