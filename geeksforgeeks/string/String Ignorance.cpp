/*https://practice.geeksforgeeks.org/problems/string-ignorance/0 */
#include<iostream>
using namespace std;

int main(int argc, char const *argv[]){
    int T;
    bool occurenece[256];
    bool out;
    char ch;
    cin >> T;
    cin.ignore(256, '\n');
    while(T--){
        string str;
        for(int i = 0; i < 256; i++){
            occurenece[i] = false;
        }
        getline(cin, str);
        for(int i = 0; i < str.length(); i++){
            ch = str[i];
            if(ch>=65 && ch<=92)
                ch += 32;
                
            if(occurenece[ch])
                out = false;
            else{
                out = true;
                cout << str[i];
            }
            occurenece[ch] = out;
        }
        
        cout << endl;
    }

    return 0;
}
