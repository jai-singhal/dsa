/*
Searching for Patterns |(Naive Pattern Searching)
Time Complexity = O(m*(n-m+1)) m=sizeof(pat), n = sizeof(txt)
*/

#include <iostream>
using namespace std;

void naivePatternMatching(string pat, string txt){
    int M = pat.length();
    int N = txt.length();
 
    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;
 
        if (j == M) 
            cout << "Match found at pos: " << i << endl;
    }
}
 
int main(){
    string txt = "AABAACAADAABAAABAA";
    string pat = "AABA";
    naivePatternMatching(pat, txt);
    return 0;
}