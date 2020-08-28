#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>
#include<algorithm>

using namespace std;

void solution(vector<vector<int>> &arr){
    unordered_set<int> rows, cols;
    int n = arr.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){ 
            if(arr[i][j] == 0){
                rows.insert(i);
                cols.insert(j);
            }
        }
    }  

    int row_flag = false, col_flag = false;
    for(int i = 0; i < n; i++){
        if(rows.find(i) != rows.end()){
            for(int j = 0; j < n; j++)
                arr[i][j] = 0;
        }
    }  

    for(int i = 0; i < n; i++){
        if(cols.find(i) != cols.end()){
            for(int j = 0; j < n; j++)
                arr[j][i] = 0;
        }

    }   

}

int main(){
    vector<vector<int>> arr = {
        {1, 0, 1},
        {1, 1, 1},
        {1, 0, 1},
    };
    solution(arr);

    int n = arr.size();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

}