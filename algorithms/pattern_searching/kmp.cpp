/*
Searching for Patterns |(KMP Algorithm)
(Knuth Morris Pratt) Pattern Searching Algorithm

Time complexity of KMP algorithm is ""O(n)"" in worst case.
*/

#include <iostream>
using namespace std;

//return an lcs array, which is an integer array that holds prefix suffix count
int* createLCS(string pat){
    int M = pat.length();
    int len = 0, i = 1;
    int* lcs = new int[M];
    lcs[0] = 0;
    while(i < M){
        if(pat[i] == pat[len])
            lcs[i++] = ++len; 
        else{
            if(len!=0) //for string like aabaaa -> 0 1 0 1 2 2
                len--;
            else{
                lcs[len] = 0;
                i++;
            }
        }
    }
    return lcs;
}


void KMP(string txt, string pat){
    int M = pat.length();
    int N = txt.length();
    int* lcs = createLCS(pat);
    int i = 0, j = 0;
    while(i < N){
        if(txt[i] == pat[j]){
            i++;
            j++;
        }
        if(j == M){
            cout << "Pattern matched from " << i-j << " to " << i << endl;
            j = lcs[j-1];
        }
        else if(i < N && txt[i] != pat[j]){
            if(j > 0)
                j = lcs[j-1];
            else
                i++;
        }
    }
}

int main(void){
    string txt = "AABAACAADAABAABA";
    string pat =  "AABA";
    KMP(txt, pat);
    return 0;
}