#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>

using namespace std;

string fractionToDecimal(int A, int B) {
    string soln;
    float result = (A*1.0)/(B*1.0);
    soln =  to_string(result);
    int i = 0;
    cout << soln << endl;
    while(soln[i++] != '.');
    int j = i;
    i++;
    char last_char = soln[i];
    int count = 1;
    while(soln[i++] == last_char){
        count++;
    }
    cout << count <<" " << i << " " << j << " " << last_char << endl;
    if(count > 3){
        if(last_char == '0')
            return soln.substr(0, j-1);
        else{
            return soln.substr(0, j) + "(" + last_char + ')'; 
        }
    }
    return soln;
}
int main(){
    int a, b;
    cin >> a >> b;
    cout << fractionToDecimal(a, b);
    return 0; 
}
