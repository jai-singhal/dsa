#include<iostream>
#include<string>

using namespace std;

int strStr(string A, string B) {
    int j, i, initial_i;
    int blen = B.length();
    int alen = A.length();
    i = 0;
    while(i < alen){
        initial_i = i;
        j = 0;

        while(j < blen && i < alen && B[j] == A[i]){
            i++;
            j++;
        };

        if(j == blen) return initial_i;
        
        i = initial_i + 1;
    }
    return -1;
}

int main(){
    string s1 = "b";
    string s2 = "b";
    cout << strStr(s1, s2);
}
// bbaabbbbbaabbaabbbbbbabbbabaabbbabbabbbbababbbabbabaaababbbaabaaaba