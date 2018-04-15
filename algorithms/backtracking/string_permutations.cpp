// Problem STatement: 
// https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/

#include <iostream>
using namespace std;
template<typename t>
void swap(const t &a, const t &b){
    t c;
    c = a;
    a = b;
    b = c;
}
void permute(string str, int l, int r){
    if(l == r){
        for(int i = 0; i < str.length(); i++){
            cout << str[i] << " ";
        }   
        cout << endl;     
    }
    for(int i = l; i <= r; i++){
        swap(str[i], str[l]);
        permute(str, l+1, r);
        swap(str[l], str[i]);
    }
}

int main(){
    string s = "ABC";
    permute(s, 0, s.length()-1);
    return 0;
}