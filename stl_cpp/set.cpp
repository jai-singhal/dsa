#include<iostream>
#include<set>
#include "readInput.h"

using namespace std;

int main(){
    set<int> mySet;
    set<int> :: iterator its;

    vector<int> v = readFileAndMakeVector();
    vector<int> :: iterator itv;
    
    for(itv = v.begin(); itv != v.end(); itv++){
        mySet.insert(*itv);
    }
    
    cout << "Number of duplicates: " << v.size() - mySet.size();
    

    return 0;
}