   /* C++ Program to find LCA of n1 and n2 using one traversal of Binary Tree */
#include <iostream> 
#include <vector> 

using namespace std; 

vector<vector<int> > generateMatrix(int n) {
    int N = n;
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    int i = 0, j = 0;
    int numb = 1;
    int c1, c2;
    while(numb < N*N){
        c1 = 0;
        while(j < n-1){
            c1++;
            matrix[i][j++] = numb++;
        }
        c2 = 0;
        while(i < n-1){
            c2++;
            matrix[i++][j] = numb++;
        }
        while(c1 > 0){
            c1--;
            matrix[i][j--] = numb++;
        }
        while(c2 > 0){
            c2--;
            matrix[i--][j] = numb++;
        }
        n = n-1;
        j++;
        i++;
    }
    if(N%2) matrix[i][j] = numb;
    
    for(int s = 0; s < N; s++){
        for(int t = 0; t < N; t++)
            cout << matrix[s][t] << " ";
        cout << endl;
    }
    return matrix;
}

int main(){
    int n = 21;
    generateMatrix(n);
}