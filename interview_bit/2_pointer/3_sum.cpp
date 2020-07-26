// https://www.interviewbit.com/problems/3-sum-zero/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int binary_search(vector<int>arr, int start, int end, int key){
    int mid = 0;
    while(start <= end){
        mid = start + (end-start)/2;
        if(key == arr[mid])
            return mid;
        if(key < arr[mid])
            end = mid - 1;
        else if(key > arr[mid])
            start = mid + 1;
    }
    return -1;
    // for(int i = start ; i <= end; i++ ){
    //     if(arr[i] == key)
    //         return i;
    // }
    // return -1;
}

int threeSumUtil(vector<int> A, int start, int end, vector<vector<int>> &sols){
    while(start < end){
        int val2 = (-1)*(A[start] + A[end]);
        int mid = binary_search(A, start + 1, end - 1, val2);
        // cout<<mid << endl;
        if(mid == -1){
            if(val2 < A[start])
                end--;
            else
                start++;
        }
        else if(mid != -1 && A[start] + A[end] + A[mid] == 0){
            vector<int> s = {A[start], A[mid], A[end]};
            
            bool isPresent = false;
            for(auto v:sols){
                if(v == s){
                    isPresent = true;
                    break;
                }
            }

            if(!isPresent){
                cout << A[start] << " " << A[mid] << " " << A[end] << endl;
                sols.push_back(s);
            }

            return 1 + 
                threeSumUtil(A, start+1, end, sols) + 
                threeSumUtil(A, start, end-1, sols);
        }
    }
    return 0;
}

vector<vector<int>> threeSum(vector<int> &A) {
    sort(A.begin(), A.end());
    int len = A.size();
    int start = 0, end = len-1;
    vector<vector<int>> sols;
    threeSumUtil(A, start, end, sols);
    return sols;
}

int main(){
    vector<int> v = {-1, 0, 1, 2, -1, -4};
    threeSum(v);
}
