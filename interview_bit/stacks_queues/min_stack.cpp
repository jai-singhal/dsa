// { Driver Code Starts
#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void push(int a);
bool isFull(int n);
bool isEmpty();
int pop();
int getMin();
stack<int> s;
priority_queue<int, vector<int>, greater<int>> min_heap;
int top = -1;

int main(){
    min_heap.push(10);
    min_heap.push(2);
    min_heap.push(51);
    min_heap.swap();

    min_heap.push(1);
    cout << min_heap.top() << endl;
    min_heap.pop();
    cout << min_heap.top() << endl;
    min_heap.push(10);
    min_heap.pop();
    cout << min_heap.top() << " " << min_heap.empty() << endl;

    min_heap.pop();
    min_heap.pop();
    min_heap.pop();
    min_heap.pop();
    min_heap.pop();
    min_heap.pop();

    cout << min_heap.top() << " " << min_heap.empty() << endl;
}// } Driver Code Ends

