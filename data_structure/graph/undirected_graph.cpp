#include<iostream>
#include<list>

using namespace std;

class UndirectedGraph{
    protected:
        int V;
        list<int> *adj;

    public:
        UndirectedGraph(int vertex){
            this->V = vertex;
            this->adj = new list<int>[vertex];
        }

        void addEdge(int src, int dest){
            this->adj[src].push_front(dest);
            this->adj[dest].push_front(src);
        }

        void printGraph(){
            list<int>::iterator it;
            for(int i = 0; i < this->V; i++){
                cout << i << " ";
                for(it = this->adj[i].begin(); it != this->adj[i].end(); it++){
                    cout << "-> " << *it;
                }
                cout << endl;
            }
        }
};

