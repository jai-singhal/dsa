   /* C++ Program to find LCA of n1 and n2 using one traversal of Binary Tree */
#include <iostream> 
#include <vector> 

using namespace std; 

int power(string A) {
    int n = A.length();
    int i = 0;
    int numb = 0;
    string res;
    while(n > 0){
        i=0;
        if(A == "2")  return 1;
        res.clear();
        n = A.length();

        while(i < n){
            if(numb == 0)
                numb = A[i] - '0';
            else
                numb = numb*10 + A[i] - '0';
            i++;
            if(numb < 2 && i < n){
                numb = numb*10 + A[i] - '0';
                // if(numb % 2 == 0)
                res.push_back('0');
                i++;
            }
            char ch = (int)(numb/2) + '0';
            res.push_back(ch);
            numb = numb%2;
        }
        if(numb) return 0;
        int j = 0;
        while(res[j++] == '0');
        j--;
        A = res.substr(j);
        // cout << res <<  endl;
    }
    
    return 1;
}

int main(){
    cout << power("2305843009213693952");
}

// 147573952589676412928
// 738281926294838206