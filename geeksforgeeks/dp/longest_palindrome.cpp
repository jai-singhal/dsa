// /Longest Palindrome in a String
// /https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string/0

#include <iostream>
#include<cmath>
using namespace std;


int PalindromDp(string str){
    int len = str.length();
    int DP[len+1][len+1] = {0};
    int maxPal = 0, maxPalIndex = 0;
    for(int i = 0; i <= len; i++){
        for(int j = 0; j <= len; j++){
            if(i == 0 || j == 0){
                DP[i][j] = 0;
            }
            else if(str[len-i] == str[j-1]){
                DP[i][j] = DP[i-1][j-1] + 1;
            }
            if((DP[i][j] > maxPal) || (DP[i][j] >= maxPal && j-1 <= maxPalIndex)){
                maxPal = DP[i][j];
                maxPalIndex = j-1;
            }
        }
    }
    for(int i = 0; i <= len; i++){
        for(int j = 0; j <= len; j++){
            cout << DP[i][j] << " ";
        }
        cout << endl;
    }
    while(maxPal > 0){
        cout << str[maxPalIndex];
        maxPalIndex--;
        maxPal--;
    }
    cout << endl;
    return DP[len][len];
}

int main(){
    int T, slen;
    cin >> T;
    string str;
    while(T--){
        cin >> str;
        slen = str.length();
        PalindromDp(str);
    }

}
//sasakjsajkjk1234321sajkskajksa