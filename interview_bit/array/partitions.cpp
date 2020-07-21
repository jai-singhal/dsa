/* https://www.interviewbit.com/problems/partitions/ */
/*
You are given a 1D integer array B containing A integers.

Count the number of ways to split all the elements of the array into
3 contiguous parts so that the sum of elements in each part is the same.
*/

#include<iostream>
#include<vector>

using namespace std;

int partitions(vector<int> B, int A, int sum){
    int sumi = 0;
    int count = 0;
    bool flag2, flag3;
    vector<int> sols1;

    for(int i = 0; i < A; i++){
        sumi += B[i];
        if(sumi == sum){
            sols1.push_back(i+1);
        }
    }

    vector<int> sols2;
    for(int i = 0; i < sols1.size(); i++){
        int j = sols1[i];
        sumi = 0;
        while(j < A){
            sumi += B[j];
            j++;
            if(sumi == sum){
                sols2.push_back(j);
            }
        }
    }

    for(int i = 0; i < sols2.size(); i++){
        int j = sols2[i];
        sumi = 0;
        while(j < A){
            sumi += B[j];
            j++;
            if(sumi == sum){
                count += 1;
                break;
            }
        }
    }
    return count;

}

int main(){
    int A, val;
    cin >> A;
    int b_sum = 0;

    vector<int> B;
    for(int i = 0; i < A; i++){
        cin >> val;
        b_sum += val;
        B.push_back(val);
    }
    cout << partitions(B, A, b_sum/3);
}