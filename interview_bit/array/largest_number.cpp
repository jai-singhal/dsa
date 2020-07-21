#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool compare_fun(string a,  string b){
    string c1 = a+b;
    string c2 = b+a;
    return c1.compare(c2) > 0;
}


int main(){
    int n, val;
    cin >> n;
    vector<string> arr;
    for(int i = 0; i < n; i++){
        cin >> val;
        arr.push_back(to_string(val));
    }
    sort(arr.begin(), arr.end(), compare_fun);
    string sol = "";
    for(int i = 0; i < n; i++){
        sol += arr[i];
        if(arr[i] == "0")
            break;
    }
    cout << sol;
}
