vector<int> prevSmaller(vector<int> &A) {
    vector<int> solution;
    stack<int> s;
    
    for(auto a:A){
        while(!s.empty() && a <= s.top()){
            s.pop();
        }
        if(s.empty())
            solution.push_back(-1);
        else
            solution.push_back(s.top());
        s.push(a);
    }
    return solution;
}
