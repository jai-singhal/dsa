#include<iostream>
#include<vector>

using namespace std;

class Node{
    public:
    int index;
    int weight;
    Node(int i, int w){
        index = i;
        weight = w;
    }
};

// struct parentNode{
//     int index;
//     int weight;
// }

class Graph{
    public:
    int V; // number of vertices
    vector<Node>* adj;

    Graph(int v){
        this->V = v;
        for(int i = 0; i < v; i++){
            adj = new vector<Node>[v];
        }
    }
    void addEdge(int src, int dst, int wt = 0){
        adj[src].push_back(Node(dst, wt));
    }

    void printGraph(){
        for(int i = 0; i < V; i++){
            cout << i << ": ";
            for(auto j:adj[i]){
                cout << "[" << j.index << ", " << j.weight << "], ";
            }
            cout << endl;
        }
    }
};

int main(){
    Graph G(4);
    G.addEdge(1, 3);
    G.addEdge(1, 2);
    G.addEdge(2, 1);
    G.addEdge(0, 2);

    G.printGraph();
}