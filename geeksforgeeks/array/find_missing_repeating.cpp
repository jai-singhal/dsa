#include<iostream>
#include<unordered_set>
#define MAXNUMB 99999999

using namespace std;
int main(void) {
    unordered_set<int> arr_set;
    int T, N, sumApparent, numb, sumReal;
    int dupNo, missedNo;
    cin >> T;
    while(T--){
        cin >> N;
        dupNo = MAXNUMB;
        sumApparent = 0;
        sumReal = N*(N+1)/2;
        for(int i = 0 ; i < N; i++){
            cin >> numb;
            sumApparent += numb;
            if(arr_set.find(numb) != arr_set.end() && numb < dupNo){
                dupNo = numb;   
            }
            else
                arr_set.insert(numb);
        }
        missedNo = dupNo - (sumApparent-sumReal);
        cout << dupNo << " " << missedNo << endl;
    }
	return 0;
}