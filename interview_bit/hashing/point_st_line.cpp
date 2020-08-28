#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<set>
#include<vector>

using namespace std;
    
int maxPoints(vector<int> &A, vector<int> &B) {
    unordered_map<float, set<int>> slope;
    int n1 = A.size();
    int n2 = B.size();
    float m;
    
    if(n1 != n2)
        return -1;
    if(n1 == 0)
        return 0;
        
    for(int i = 0; i < n1; i++){
        for(int j = i+1; j < n1; j++){
            if(A[j] - A[i] == 0)
                m = INT_MAX;
            else
                m = (B[j] - B[i])*1.0/(A[j] - A[i]);
            if(slope.find(m) == slope.end()){
                set<int> point = {i, j};
                slope.insert({m, point});
            }
            else{
                slope[m].insert(i);
                slope[m].insert(j);
            }
        }
    }
    int max_points = 0;
    for(auto a: slope){
        cout << a.first << " " << a.second.size() << endl;
        if(a.second.size() > max_points)
            max_points = a.second.size();
    }
    
    return max(max_points, 1);
}

int main(){
    vector<int> x;
    vector<int> y;
    int total, numb;
    cin >> total;
    while(total--){
        cin >> numb;
        x.push_back(numb);
        cin >> numb;
        y.push_back(numb);
    }
    cout << maxPoints(x, y);
    // 6 -6 -17 5 -16 -18 -17 2 -4 5 -13 -2 20
}
