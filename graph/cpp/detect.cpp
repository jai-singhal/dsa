#include "directed_graph.cpp"

class GraphDetect: public DirectedGraph{

    public:
        GraphDetect(int v): DirectedGraph(v){}

        bool isCycleUtil(int s, bool* visited){
            if(visited[s] == false){
                
                visited[s] = true;
                list<int>:: iterator it;
                for(it = this->adj[s].begin(); it != this->adj[s].end(); it++){
                    for(int i = 0; i < this->V; i++) //
                        cout << visited[i] << " ";   //
                    cout << endl; //
                    if( !visited[*it] && isCycleUtil(*it, visited)){
                        return true;
                    }
                    else    
                        return false;
                }
            }
                
            
        }

        bool isCycle(){
            bool* visited = new bool[this->V];
            for(int i = 0; i < this->V; i++)
                visited[i] = false;

            for(int i = 0; i < this->V; i++)
                cout << isCycleUtil(i, visited) << endl;   
        }
};


int main(void){
    GraphDetect g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.printGraph();
    g.isCycle();
    return 0;
}

