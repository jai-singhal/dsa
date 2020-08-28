#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

vector<int> repeatedNumber(vector<int> &A){
    int n = A.size();
    int sum = n*(n+1)/2;

    vector<int>sols(2);

    vector<int> mapp(n+2, 0);
    
    for(int i = 0; i < n; i++){
        mapp[A[i]]++;
    }

    for(int i = 1; i <= n; i++){
        if(mapp[i] == 2)
            sols[0] = i;
        if(mapp[i] == 0)
            sols[1] = i;
    }
    
    cout << sols[0] << " " << sols[1] << endl;
    return sols;
}

int main(){
    int n, val;
    cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++){
        cin >> val;
        arr.push_back(val);
    }
    repeatedNumber(arr);
    return 0;
}