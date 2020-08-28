// https://www.hackerrank.com/contests/bppc14/challenges/string-and-performing-queries
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    int a, b, Q;
    string r, s;
    bool is_rev = false;

    cin >> s;
    cin >> Q;
    for(int i = 0; i < Q; i++){
        cin >> a;
        if (a == 1)
           is_rev = true; 
        else{
            cin >> b;
            cin >> r;
            if(is_rev){
                if(b == 2) b = 1;
                else b = 2;
                is_rev = false;
            }
            if (b == 1)
                s = r + s;
            else if(b == 2)
                s = s + r;
        }
    }
    if(is_rev)
        reverse(s.begin(), s.end());
    cout << s;
    return 0;
}

            