#include "../directed_graph.cpp"

class GraphDetect: public DirectedGraph{

    public:
        GraphDetect(int v): DirectedGraph(v){}

        bool isCycleUtil(int s, bool* visited, bool* recursionStack){
            
            if( !visited[s] ){
                visited[s] = true;
                recursionStack[s] = true;
                list<int>:: iterator it;
                for(it = this->adj[s].begin(); it != this->adj[s].end(); it++){
                    if( !visited[*it] && isCycleUtil(*it, visited, recursionStack))
                        return true;
                    else if (recursionStack[*it]) // if the value found in recursion stack
                        return true;       
                }
            }
            recursionStack[s] = false;
            return false;
        }

        bool isCycle(){
            bool* visited = new bool[this->V];
            bool* recursionStack = new bool[this->V];
            int i, j;
            for(j = 0;  j < this->V; j++){
                visited[j] = false;
                recursionStack[j] = false;
            }
                
            for(i = 0; i < this->V; i++){
                if (isCycleUtil(i, visited, recursionStack))
                    return true;  
            }
            return false;
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
    cout << g.isCycle();
    return 0;
}

