#include<iostream>
#include<climits>
using namespace std;

class BinaryMaxHeap{
    int *array;
    int capacity;
    int heap_size;

public:
    BinaryMaxHeap(int capacity){
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

    int getMax(){
        return this->array[0];
    }

    int extractMax(){
        if(heap_size <= 0)
            return INT_MIN;
        if(heap_size == 1){
            heap_size--;
            return array[0];
        }
        this->array[0] = this->array[this->heap_size-1];
        this->heap_size--;
        maxHeapify(0);
    }

    void increaseKey(int i, int val){ //logn
        this->array[i] -= val;
        
        while(i!=0 && this->array[parent(i)] < this->array[i]){
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

        while(i!=0 && this->array[parent(i)] < this->array[i]){
            swap(this->array[parent(i)], this->array[i]);
            i = parent(i);
        }
    }

    void deleteElementAtIndex(int i){  //logn
        increaseKey(i, INT_MAX);
        extractMax();
    }

    void maxHeapify(int i){ // O(logn)
        int l = left(i);
        int r = right(i);
        int largest = i;
        if(l < this->heap_size && this->array[l] > this->array[largest])
            largest = l;
        if(r < this->heap_size && this->array[r] > this->array[largest])
            largest = r;
        if(i!=largest){
            swap(this->array[i], this->array[largest]);
            maxHeapify(largest);
        }
        
    }

    void heapify(int i, int n){ // O(logn)
        int l = left(i);
        int r = right(i);
        int largest = i;
        if(l < n && this->array[l] > this->array[largest])
            largest = l;
        if(r < n && this->array[r] > this->array[largest])
            largest = r;
        if(i!=largest){
            swap(this->array[i], this->array[largest]);
            heapify(largest, n);
        }
        
    }

    void heapSort(){
        for(int i = heap_size-1; i >= 0; i--){
            swap(array[i], array[0]);
            heapify(0, i);
        }
    }

    void printTree(){
        for(int i = 0; i < this->heap_size; i++)
            cout << this->array[i] << " ";
    }


};
