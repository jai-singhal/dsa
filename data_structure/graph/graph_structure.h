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
};
