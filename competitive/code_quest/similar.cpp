#include<iostream>
using namespace std;
struct Mystring{
    char c;
    int freq;
};
int main(){
    int N, Q, P;
    string str;
    cin >> N;
    cin >> str;
    Mystring mystr[N];
    int freq[26] = {0};
    for(int i = 0; i < N; i++){
        mystr[i].c = str[i];
        freq[str[i]-'a']++;
        mystr[i].freq = freq[str[i]-'a'];
    }
    cin >> Q;
    bool flag = false;
    while(Q--){
        cin >> P;
        flag = false;
        for(int i = P-2; i >= 0; i--){
            if(str[i] == str[P-1]){
                cout << mystr[i].freq << endl;
                flag = true;
                break;
            }
        }
        if(!flag)
           cout << 0 << endl;
    }
    return 0;
}

/*
9
abacsddaa
2
9
3
*/
