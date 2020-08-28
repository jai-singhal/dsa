// Maximum sum increasing subsequence

#include<iostream>
using namespace std;
int main(void) {
    int T,N, numb, lastNumb, maxSum, currSum;
    int* arr;
    
    cin >> T;
    while(T--){
        cin >> N;
        lastNumb = 0;
        maxSum = 0;
        currSum = 0;
        for(int i = 0; i < N; i++){
            cin >> numb;
            if(numb >= lastNumb){
                currSum += numb;
            }
            else{
                if(currSum > maxSum){
                   maxSum = currSum;
                   currSum = numb;
                }
            }
            lastNumb = numb;
        }
        cout << maxSum << endl;

    }
	return 0;
}