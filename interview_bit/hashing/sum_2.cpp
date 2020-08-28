#include<iostream>
#include<vector>
#include<map>

using namespace std;

vector<int> twoSum(const vector<int> &A, int target) {
        
    map<int, int> numbers;

    vector<int> solution(2);
    // numbers.insert({target - A[0], 1});
    
    for(int i = 0; i < A.size(); i++){
        //not exists
        if(numbers.find(A[i]) != numbers.end()){
            solution[0] = numbers.find(A[i])->second ;
            solution[1] = i+1;
            break;
        }
        else
            numbers.insert({target - A[i], i+1});
    }

    return solution;
}

int main(){
    vector<int> arr = {2, 7, 11, 15};
    int target=9;
    vector<int> sol = twoSum(arr, target);
    cout << sol[0] << " " << sol[1] << endl;
}