#include<iostream>
using namespace std;

struct AdjListNode{
  int dest;
  AdjListNode* next;
};

struct AdjList{
  AdjListNode* head;
};

struct AdjGraph{
  int V;
  AdjList* array;
}

int main(void){
  return 0;

}
