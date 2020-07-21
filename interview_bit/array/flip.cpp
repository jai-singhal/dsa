/* https://www.interviewbit.com/problems/flip/ */

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

vector<int> flip(string A) {
    int n = A.length();
    int pointera = 0, pointerb = 0;
    vector<int> sols(2, 0);
    int maxCount = 0;
    int i = 0;

    while(i < n){
        if(A[i] == '0'){
            pointera = i;
            pointerb = i+1;
            while(A[pointerb] == '0' && pointerb < n){
                pointerb++;
            }
            if(pointerb - pointera > maxCount){
                maxCount = pointerb - pointera;
                sols[0] = pointera + 1;
                sols[1] = pointerb;
            }
            i = pointerb;
        }
        else{
            i++;
        }
    }
    if(maxCount == 0){
        vector<int> emptysol;
        return emptysol;
    }
    cout << sols[0] << " " << sols[1] << endl;
    return sols;
}

int main(){
    string A;
    cin >> A;
    flip(A);
}
