#include<iostream>
#include<string>

using namespace std;

string countAndSay(int A) {
    string current = "1";
    char ch;
    int j, count;
    for(int i = 2; i <= A; i++){
        string next = ""; 
        j = 0;
        while(j < current.length()){
            count = 1;
            ch = current[j];
            while(ch == current[++j]) count++;
            next += to_string(count);
            next += ch;
        }
        current = next;
    }
    return current;
}

int main(){
    int N;
    cin >> N;
    cout << countAndSay(N);
}

