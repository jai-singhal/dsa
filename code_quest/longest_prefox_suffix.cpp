#include <iostream>
using namespace std;

int maxElement(int* arr, int n){
    int max = 0;
    for(int i = 0; i < n; i++)
        if(arr[i] > max)
            max = arr[i];
            
    return max;
}

int createLCS(string pat){
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
    int max = maxElement(lcs, M);
    delete []lcs;
    return max;
}


int main(void){
    int t;
    string pat;
    cin >> t;
    while(t--){
        cin >> pat;
        cout << createLCS(pat) << endl;
    }
    return 0;
}