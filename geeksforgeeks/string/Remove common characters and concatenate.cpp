#include<iostream>
#include<map>
#include<iterator>
using namespace std;
int main(void) {
    int T;
    string s1, s2;
    
    cin >> T;
    cin.ignore(256, '\n');
    while(T--){
        cin >> s1;
        cin >> s2;
        string sOut2 = "";
        string sOut1 = "";

        map<char, int> existence;
        for(int i = 0; i < s1.length(); i++)
            existence.insert(pair<char, int>(s1[i], 1));
               
        for(int i = 0; i < s2.length(); i++){
            if(existence.find(s2[i]) == existence.end())
                sOut2 += s2[i];
            else
                existence[s2[i]] = 0;
        }
        for(int i = 0; i < s1.length(); i++){
            if(existence.find(s1[i]) != existence.end() && existence[s1[i]] != 0){
                sOut1 += s1[i];
            }
        }
        if((sOut1+sOut2).length() == 0)
            cout << -1 << endl;
        else
            cout << sOut1 + sOut2 << endl;
    }
	return 0;
}