#include<iostream>
#include<climits>
#include<list>
using namespace std;

class BinaryMinHeap{
    int *array;
    int capacity;
    int heap_size;

public:
    BinaryMinHeap(int capacity){
        array =  new int[capacity]; 
        this->capacity = capacity;
        this->heap_size = 0;
    }
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }

    int left(int i){
        return 2*i+1;
    }

    int right(int i){
        return 2*i+2;
    }

    int parent(int i){
        return i/2;
    }

    int getMin(){
        return this->array[0];
    }

    int extractMin(){
        if(heap_size <= 0)
            return INT_MAX;
            

    }

    void decreaseKey(int i, int val){ //logn
        this->array[i] -= val;
        
        while(i!=0 && this->array[parent(i)] > this->array[i]){
            swap(this->array[parent(i)], this->array[i]);
            i = parent(i);
        }      

    }

    void insert(int key){  //O(logn)
        if(this->heap_size > this->capacity){
            cout << "Heap overflow" << endl;
            return;
        }

        this->heap_size++;
        int i = this->heap_size - 1;
        this->array[i] = key;

        while(i!=0 && this->array[parent(i)] > this->array[i]){
            swap(this->array[parent(i)], this->array[i]);
            i = parent(i);
        }
    }

    void deleteElement(int i){  //logn
        decreaseKey(i, INT_MIN);
        extractMin();
    }

    void minHeapify(){ // O(logn)

    }

    void printTree(){
        for(int i = 0; i < this->heap_size; i++)
            cout << this->array[i] << " ";
    }


};


int main(){

    BinaryMinHeap heap = BinaryMinHeap(10);

    heap.insert(9);
    heap.insert(1);
    heap.insert(7);
    heap.insert(4);
    heap.insert(5);
    
    heap.printTree();

    return 0;
}