#include<iostream>
#include<list>

using namespace std;

class Node{
    public:
        int vertex;
        int weight;
   
        Node(int v, int w){
            vertex = v;
            weight = w;
        }
};

class UndirectedWeightedGraph{
    protected:
        int V;
        list<Node> *adj;

    public:
        UndirectedWeightedGraph(int vertex){
            this->V = vertex;
            this->adj = new list<Node>[vertex];
        }

        void addEdge(int src, int dest, int wt){
            Node newNode1 = Node(src, wt);
            Node newNode2 = Node(dest, wt);
            this->adj[src].push_front(newNode2);
            this->adj[dest].push_front(newNode1);
        }

        void printGraph(){
            list<Node>::iterator it;
            for(int i = 0; i < this->V; i++){
                cout << i << " ";
                for(it = this->adj[i].begin(); it != this->adj[i].end(); it++){
                    cout << "-> v=" << (*it).vertex << ",w=" << (*it).weight;
                }
                cout << endl;
            }
        }
};


// int main(){

//     UndirectedWeightedGraph G = UndirectedWeightedGraph(6);
//     G.addEdge(1, 3, 5);
//     G.addEdge(4, 3, 2);
//     G.addEdge(1, 5, 7);
//     G.addEdge(1, 2, 1);
//     G.addEdge(2, 5, 10);
//     G.printGraph();
    
//     return 0;
// }