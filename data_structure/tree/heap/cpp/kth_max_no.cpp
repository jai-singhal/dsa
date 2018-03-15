#include<iostream>
#include<algorithm> // for heap operations
#include<vector>
using namespace std;

int main(void){
    vector <int> v1 = {20, 30, 40, 25, 15}; // create a vector
    make_heap(v1.begin(), v1.end()); //create a heap from vector begin to end O(n)
    
    cout << "The maximum element of heap is : " << v1.front() << endl; //print max element from the heap

    int k = 3;
    for(int i = 0; i < k; i++){ // extract the max element
        pop_heap(v1.begin(), v1.end()); //extracts the max element
        v1.pop_back(); //heapify the tree on pop operation
    }

    cout << k << "th max number is " << v1.front() << endl;     

    return 0;
}