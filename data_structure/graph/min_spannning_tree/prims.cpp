#include<iostream>
#include "../unidi_with_wt_graph.cpp"
#include "../../tree/heap/binary_min_heap.cpp"
using namespace std;


class PrimsAlgorithm{
    private:
        UndirectedWeightedGraph* G;
        int V;
        int* parent;
        int* key;
        bool* mstSet;

        BinaryMinHeap* H;

    public:
        PrimsAlgorithm(UndirectedWeightedGraph* G, int v){
            this->V = v;
            this->G = G;

            this->parent = new int[v];
            this->key = new int[v];
            this->mstSet = new bool[v];

            this->H = new BinaryMinHeap(v);

            this->H->insert(0);
            this->parent[0] = -1;
            this->key[0] = 0;
            this->mstSet[0] = true;
            for (int i = 1; i < v; i++){
                this->parent[i] = -1;
                this->key[i] = INT_MAX;
                this->mstSet[i] = false;
                this->H->insert(INT_MAX);
            }
        }

        void printSoln(){
            for(int i = 0; i < this->V; i++){
                cout << i << " " << key[i] << " " << parent[i] << endl;
            }
        }


        void primsMST(){
            while(!H->isEmpty()){
                H->printTree();
                int u = H->extractMin();
                H->minHeapify(0);
                cout << endl << u << endl;
                list<Node>::iterator it;
                for(it = this->G->adj[u].begin(); it != this->G->adj[u].end(); it++){
                    // cout << it->vertex << "x" << it->weight << endl;
                    if(!this->mstSet[it->vertex]){
                        if(H->array[it->vertex] > it->weight){
                            H->array[it->vertex] = it->weight;
                            H->minHeapify(0);
                            H->printTree();
                            cout << endl;
                            key[it->vertex] = it->weight;
                            parent[it->vertex] = u;
                            this->mstSet[it->vertex] = true;
                        }
                    }
                }
            }

        }
};

int main(){
    UndirectedWeightedGraph* G = new UndirectedWeightedGraph(9);
    G->addEdge(0, 1, 4);
    G->addEdge(1, 2, 8);
    G->addEdge(2, 3, 7);
    G->addEdge(3, 4, 9);
    G->addEdge(0, 7, 8);
    G->addEdge(1, 7, 11);
    G->addEdge(7, 8, 8);
    G->addEdge(7, 6, 1);
    G->addEdge(2, 8, 2);
    G->addEdge(8, 6, 6);
    G->addEdge(6, 5, 2);
    G->addEdge(2, 5, 4);
    G->addEdge(3, 5, 14);
    G->addEdge(5, 4, 10);
    
    PrimsAlgorithm* P = new PrimsAlgorithm(G, 9);
    P->primsMST();
    cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
    P->printSoln();
    return 0;
}