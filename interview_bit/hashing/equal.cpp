
#include<iostream>
#include<map>
#include<vector>

using namespace std;

bool compare(vector<int> a, vector<int> b){
    for(int i = 0; i < 4; i++){
        if(a[i] < b[i])
            return true;
        else if(a[i] > b[i])
            return false;
    }
    return false;
}

vector<int> equal(vector<int> &A) {
    int alen = A.size();
    vector<int> solution;
    map<int, pair<int, int>> sum_4;
    for(int i = 0; i < alen; i++){
        for(int j = i+1; j < alen; j++){
            int s = A[i] + A[j];
            if(sum_4.find(s) == sum_4.end()){
                pair<int, int>p(i, j);
                sum_4.insert({s,  p});
            }
            else{
                pair<int, int>p = sum_4[s];
                if( (i != p.first && i != p.second) &&
                    (j != p.first && j != p.second))
                {
                    // cout << p.first << " " << p.second << " " << i << " " << j << "|| ";
                    vector<int> newSol = {p.first, p.second, i, j};
                    if(solution.size() == 0)
                        solution = newSol;
                    else if(compare(newSol, solution))
                        solution = newSol;
                    // cout << solution[0] << " " << solution[1] << " " << solution[2] << " " << solution[3] << endl;
                }
                    
            }
        }
    }
    cout << endl;
    // cout << solution[0] << " " << solution[1] << " " << solution[2] << " " << solution[3] << endl;
    return solution;
}

int main(){
    vector<int> s = { 9, 5, 4, 9, 3, 6, 8, 7, 1, 2, 8, 7, 2, 9, 7, 1, 3, 9, 7, 8, 1, 0, 5, 5};
    vector<int> sol = equal(s);

}