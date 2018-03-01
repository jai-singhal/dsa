#include<iostream>
#include "graph.h"

using namespace std;


AdjListNode* addNode(int val){
  AdjListNode* newNode = new AdjListNode;
  newNode->dest = val;
  newNode->next = NULL;
  return newNode;
}

void addEdge(AdjGraph* G, int src, int dest){
  if(src > G->V){
    cout << "Vertex out of range";
    return;
  }
  AdjListNode* newNode = addNode(dest);
  AdjListNode* temp = G->array[src].head;
  G->array[src].head = newNode;
  if(G->array[src].head != NULL)
    newNode->next = temp;
}

AdjGraph* createGraph(int totalVertex){
  AdjGraph* G = new AdjGraph;
  G->V = totalVertex;
  G->array = new AdjList[totalVertex];
  for(int i = 0; i < totalVertex; i++){
    G->array[i].head = NULL;
  }
  return G;
}

void printGraph(AdjGraph* G){
  for(int i = 0; i < G->V; i++){
    AdjListNode* temp = G->array[i].head;
    cout << i << ": ";
    while (temp) {
      cout << temp->dest << "->";
      temp = temp->next;
    }
    cout << endl;
  }
}

int main(void){
  AdjGraph* G = createGraph(10);
  addEdge(G, 4, 10);
  addEdge(G, 6, 9);
  addEdge(G, 1, 4);
  addEdge(G, 2, 6);
  addEdge(G, 2, 9);
  addEdge(G, 4, 6);
  printGraph(G);
  return 0;
}
