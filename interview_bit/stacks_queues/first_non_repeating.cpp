#include<iostream>
#include<vector>
#include<queue>

using namespace std;

string solve(string A) {
    queue<char>q;
    int n = A.length();
    q.push(A[0]);
    char last_char = A[0];
    string solution = "";
    solution += last_char;

    for(int i = 1; i < n; i++){
        if(A[i] == last_char){
            q.pop();
            if(!q.empty())
                last_char = q.front();
            else
                last_char = '#';
        }
        else
            q.push(A[i]);

        solution += last_char;
    }
    return solution;
}


int main(){
    string q = "abcabc";
    cout << solve(q) << endl;
}