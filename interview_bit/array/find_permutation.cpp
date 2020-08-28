#include<iostream>
#include<vector>
#include<stack>
#include<string>

using namespace std;

vector<int> findPerm(const string A, int B) {
    vector<int> solution;
    stack<int> Inc;
    stack<int> Dec;
    int start = 1;
    int end = B;

    for(auto s:A){
        if(s == 'I')
            Inc.push(end--);
        else if(s == 'D')
            Dec.push(start++);
    }

    if(!Dec.empty())
        solution.push_back(Dec.top() + 1);
    else if(!Inc.empty())
        solution.push_back(Inc.top() - 1);
    else
        return solution;
    for(auto s:A){
        if(s == 'I'){
            solution.push_back(Inc.top());
            Inc.pop();
        }
        else if(s == 'D'){
            solution.push_back(Dec.top());
            Dec.pop();
        }
    }
    return solution; 
}

int main(){
    string ID;
    int N;
    cin >> ID;
    cin >> N;
    vector<int> sol = findPerm(ID, N);
    for(auto s:sol){
        cout << s << " ";
    }
    cout << endl;

}
