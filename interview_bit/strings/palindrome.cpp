#include<iostream>
#include<string>

using namespace std;

int isPalindrome(string A) {
    int start = 0, end = A.length();
    while(start < end){
        char ch1 = A[start];
        char ch2 = A[end];

        if(ch1 >= 'a' && ch1 <= 'z' || ch1 >= '0' && ch1 <= '9')
            ch1 = ch1;
        else if(ch1 >= 'A' &&  ch1 <= 'Z')
            ch1 = ch1 - 'A' + 'a';
        else{
            start++;
            continue;
        }
        
        if(ch2 >= 'a' && ch2 <= 'z' || ch2 >= '0' && ch2 <= '9')
            ch2 = ch2; 
        else if(ch2 >= 'A' &&  ch2 <= 'Z')
            ch2 = ch2 - 'A' + 'a';
        else{
            end--;
            continue;
        }

        // cout << ch1 << " " << ch2 << endl; 
        if(ch1 != ch2)  return 0;
        else {
            start++;
            end--;
        }
    }
    return 1;
}

int main(){
    string s ="1a2";
    cout << isPalindrome(s);
}
