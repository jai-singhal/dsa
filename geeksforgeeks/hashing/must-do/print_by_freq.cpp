#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int, int> &i1, const pair<int, int> &i2) { 
    if(i1.second == i2.second)
        return (i1.first < i2.first); 
    return (i1.second > i2.second); 
} 

int main(){
    int T, N, numb;
    cin >> T;
    while(T--){
        cin >> N;
        unordered_map<int, int> freq;
        for(int i = 0; i < N; i++){
            cin >> numb; 
            if(freq.find(numb) == freq.end()){
                freq.insert(make_pair(numb, 1));
            }
            else{
                freq.at(numb)++;
            }
        }
        
        vector<pair<int, int>> v;
        for(auto &i:freq){
            v.push_back(make_pair(i.first, i.second));
        }
        
        sort(v.begin(), v.end(), compare);
        for(auto &i:v){
            for(int j = 0; j < i.second; j++)
                cout << i.first << " ";
        }
        cout << endl;

    }
}