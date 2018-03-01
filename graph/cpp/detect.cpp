#include<iostream>
#include "directed_graph.cpp"

class GraphDetect: public DirectedGraph{

    public:
        GraphDetect(int v): DirectedGraph(v){}

        bool isCycleUtil(int s, bool* visited){
            
        }

        bool isCycle(){
            bool* visited = new bool[this->V];
            for(int i = 0; i < this->V; i++)
                visited[i] = false;

            cout << isCycleUtil(0, visited);            
        }
};