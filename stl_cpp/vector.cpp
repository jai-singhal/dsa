#include<iostream>
#include<vector>
#include "readInput.h"
using namespace std;


int main(){

    vector <int> v1 = readFileAndMakeVector();
    

    cout << v1.front() << endl;
     
    return 0;
}