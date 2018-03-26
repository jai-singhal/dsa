#include<iostream>
#include <climits>
using namespace std;

class Queue{
    int f, r, size, capacity;
    int* array;

public:
    Queue(int capacity = 100){
        this->capacity = capacity;
        this->array = new int[capacity];
        this->size = 0;
        this->f = this->r = 0;
    }

    void enqueue(int value){
        if(this->size > this->capacity){
            cout << "Queue Overflow" << endl;
            return;
        }
        this->array[(r+1)%capacity] = value;
        this->r += 1;
        this->size += 1;
    }
    
    void dequeue(){
        if(isEmpty()){
            cout << "Queue Underflow" << endl;
            return;
        }
        this->array[(this->f+1)%capacity] = -1;
        this->f += 1;
        this->size +=1;
    }
    
    bool isEmpty(){
        return this->size == 0;
    }

    int front(){
        if(isEmpty()){
            return INT_MIN;
        }
        return array[f];
    }

    int rear(){
        if(isEmpty()){
            return INT_MIN;
        }
        return array[r];   
    }

};