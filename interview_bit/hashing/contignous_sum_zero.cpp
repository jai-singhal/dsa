#include<iostream>
#include<vector>
#include<map>

using namespace std;

vector<int> findContigousSubarraySumZero(vector<int> arr){
    map<int, int> sum_index;
    int n = arr.size();
    int sum = 0;
    int max_count = 0;
    int end = -1;
    for(int i = 0; i < n; i++){
        sum = sum + arr[i];
        if (sum == 0) {
            max_count = i + 1; 
            end = i + 1;
        }
        if(sum_index.find(sum) == sum_index.end()){
            sum_index.insert({sum, i});
        }
        else{
            if(i-sum_index[sum] > max_count){
                max_count = i-sum_index[sum];
                end = i + 1;
            }
        }
    }
    cout << end-max_count << " " << end << " " << max_count << endl;
    // cout << max_count;
    vector<int>sol;
    
    if(max_count == 0)
        return sol;
        
    for(int i = end-max_count; i < end; i++){
        sol.push_back(arr[i]);
    }
    return sol;
}

int main(){
    vector<int> arr = { -1, 1, 1, -1, -1, 1, 1, -1 };
    vector<int> sol = findContigousSubarraySumZero(arr);
    for(auto s: sol){
        cout << s << " ";
    } 
}

abbaccaaabcabbbccbabbccabbacabcacbbaabbbbbaaabaccaacbccabcbababbbabccabacbbcabbaacaccccbaabc
abaabaaaabcaabcacabaa