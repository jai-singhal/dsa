#include "../directed_graph.cpp"

class GraphDetect: public DirectedGraph{

    public:
        GraphDetect(int v): DirectedGraph(v){}

        bool isCycleUtil(int s, bool* visited){
            
            if( !visited[s] ){
                visited[s] = true;
                list<int>:: iterator it;
                cout << s << " x " << visited[s] << endl;                
                for(it = this->adj[s].begin(); it != this->adj[s].end(); it++){
                    if( !visited[*it] && isCycleUtil(*it, visited))
                        return true;
                    else    
                        return false;
                }
            }
        }

        bool isCycle(){
            bool* visited = new bool[this->V];
            int i, j;
            for(j = 0;  j < this->V; j++)
                visited[j] = false;
            for(i = 0; i < this->V; i++){

                
                if (isCycleUtil(i, visited))
                    return true;  
                cout << endl;
            }
            return false;
        }
};


int main(void){
    GraphDetect g(2);
    g.addEdge(0, 1);
    g.addEdge(0, 0);
    // g.addEdge(2, 3);
    g.printGraph();
    cout << g.isCycle() << "ans";
    return 0;
}

