#include<iostream>
#include "queue.h"
using namespace std;

int main(){
    Queue q(100);
    q.enqueue(19);
    q.enqueue(10);
    q.enqueue(29);
    q.enqueue(49);
    q.enqueue(39);
    q.dequeue();
    q.enqueue(99);
    q.dequeue();

    cout << "Front is: " << q.front() << endl;
    cout << "Rear is: " << q.rear() << endl;
    return 0;
}
