#include "binary_min_heap.h"
#include "binary_max_heap.h"
using namespace std;

int main(){

    BinaryMinHeap minHeap = BinaryMinHeap(10);
    minHeap.insert(9);
    minHeap.insert(1);
    minHeap.insert(7);
    minHeap.insert(4);
    minHeap.insert(5);
    
    minHeap.deleteElementAtIndex(1);

    cout << "Min Heap" << endl;
    minHeap.printTree();
    cout << endl;
    minHeap.heapSort();
    cout << "Descending sort: " << endl;
    minHeap.printTree();
    cout << endl << endl;



    cout << "Max Heap" << endl;
    BinaryMaxHeap maxHeap = BinaryMaxHeap(10);
    maxHeap.insert(12);
    maxHeap.insert(11);
    maxHeap.insert(13);
    maxHeap.insert(5);
    maxHeap.insert(6);
    maxHeap.insert(7);
    
    // maxHeap.deleteElementAtIndex(1);
    maxHeap.printTree();
    cout << endl;

    maxHeap.heapSort();
    cout << "Ascending sort: " << endl;
    maxHeap.printTree();
    cout << endl;
    return 0;
}