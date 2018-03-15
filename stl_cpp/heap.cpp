#include <iostream>
#include "readInput.h"
#include <algorithm>
using namespace std;

int main(){
    vector<int> v = readFileAndMakeVector();
    vector<int>::iterator it;
    
    make_heap(v.begin(), v.end()); // created a max heap
    cout << "Max element in heap: " << v.front() << endl;
    
    //push element in heap
    v.push_back(10500);
    //reorder the pushed element
    push_heap(v.begin(), v.end());
    cout << "Max element in heap after push and heapify: " << v.front() << endl;

    // pop element in heap: removes the max element from the heap    
    pop_heap(v.begin(), v.end());
    cout << "Max element in heap after pop and heapify: " << v.front() << endl;

    //sort_heap
    sort_heap(v.begin(), v.end());
    for (it = v.begin(); it != v.end(); it++) 
       cout << *it << " ";

    return 0;
}