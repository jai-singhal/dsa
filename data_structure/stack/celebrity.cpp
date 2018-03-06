#include<iostream>
#include "Stack.h"
#define N 20

using namespace std;

/*
The Celebrity Problem
---------------------
In a party of N people, only one person is known to everyone. Such a person may be present in the 
party, if yes, (s)he doesn’t know anyone in the party. We can only ask questions like “does A know B?“
Find the stranger (celebrity) in minimum number of questions.

We can describe the problem input as an array of numbers/characters representing persons in the party. 
We also have a hypothetical function HaveAcquaintance(A, B) which returns true if A knows B, false 
otherwise. How can we solve the problem.
*/

class CelebrityProblem{

    int** MATRIX;
    Stack<int> s;

public:
    CelebrityProblem(int n){
        int MATRIX[4][4] = {
                            {0, 0, 1, 0},
                            {0, 0, 1, 0},
                            {0, 0, 0, 0},
                            {0, 0, 1, 0}
                        };
        for(int i = 0; i < n; i++){
            s.push(i);
        }
    }

    bool knows(int a, int b){
        cout << a << "," << b <<endl;
        cout<< MATRIX[1][1];
        return 0;
    }

    int celebrity(){
        //pop 2 elements
        int A = s.pop();
        int B = s.pop();
         cout<< knows(A,B);  
        // while( !s.is_empty() ){
        //           
        //     // if(knows(A, B)){
        //     //     A = s.pop();
        //     // }
        //     // else{
        //     //     B = s.pop();
        //     // }
        // }

        return s.top_of_stack();
    }


};

int main(){
    CelebrityProblem c1 = CelebrityProblem(4);
    cout << c1.celebrity();
}