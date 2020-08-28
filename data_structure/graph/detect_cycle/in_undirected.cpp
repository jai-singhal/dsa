#include "../undirected_graph.cpp"

class DetectCycle: public UndirectedGraph{
    public:
        DetectCycle(int v):UndirectedGraph(v){}

        bool isCycleUtil(int s, bool* visited, int parent){
            visited[s] = true;
            list<int>:: iterator it;
            for(it = this->adj[s].begin(); it != this->adj[s].end(); it++){
                if( !visited[*it] ){
                    if( isCycleUtil(*it, visited, s) )
                        return true;
                }
                else if(*it != parent)
                    return true;
            }
            return false;
        }

        bool isCycle(){
            bool* visited = new bool[this->V];
            int i, j;
            for(j = 0;  j < this->V; j++)
                visited[j] = false;
            
            for(i = 0; i < this->V; i++){
                if (!visited[i] && isCycleUtil(i, visited, -1))
                    return true;  
            }
            return false;
        }
};

int main(){
    DetectCycle g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 0);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isCycle()? cout << "Graph contains cycle\n":
                   cout << "Graph doesn't contain cycle\n";
 
    DetectCycle g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.isCycle()? cout << "Graph contains cycle\n":
                   cout << "Graph doesn't contain cycle\n";

}