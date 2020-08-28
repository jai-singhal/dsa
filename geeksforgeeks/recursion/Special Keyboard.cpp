#include<iostream>
using namespace std;
int maxCount = 0;

// METHOD 1 
int SpecialKeyboard(int N, int select, int cp, int cnt){
    if(maxCount < cnt)
        maxCount = cnt;

    if(N == 0)
        return 0;

    SpecialKeyboard(N-1, select, cp, cnt + 1); // Write 'A'
    if(cnt)
        SpecialKeyboard(N-1, cnt, select, cnt); // select
    if(select)
        SpecialKeyboard(N-1, select, select, cnt);  // cp
    if(cp)
        SpecialKeyboard(N-1, select, cp, cnt + select); //paste

}

// METHOD 2
int SpecialKeyboardRecusrion(int n){
    if(n <= 6)
        return n;
    return max(3*SpecialKeyboardDP(n-4), 4*SpecialKeyboardDP(n-5));
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        // maxCount = 0;
        // SpecialKeyboard(N, 0, 0, 0);
        cout << SpecialKeyboardRecusrion(N) << endl;        
    }

}
