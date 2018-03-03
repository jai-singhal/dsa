#include "directed_graph.cpp"

class GraphTraversal: public DirectedGraph{
    public:
        GraphTraversal(int v): DirectedGraph(v){}

        void BFS(int start){
            bool* visited = new bool[this->V];
            for(int i = 0; i < this->V; i++)
                visited[i] = false;
            list<int> queue;
            queue.push_front(start);
            
            while( !queue.empty() ){
                start = queue.front();
                cout << start << " ";
                queue.pop_front();
                visited[start] = true;
                list<int>::iterator it;
                for(it = this->adj[start].begin(); it != this->adj[start].end(); it++){
                    if(!visited[*it]){
                        visited[*it] = true;
                        queue.push_back(*it);
                    }
                }
            }
            cout << endl;
        }


        void DfsUtil(int s, bool* visited){
            visited[s] = true;
            cout << s << " ";  
            list<int>::iterator it;
            for(it = this->adj[s].begin(); it != this->adj[s].end(); it++){
                if(!visited[*it]){  
                    DfsUtil(*it, visited);
                }
            }
        }

        void DFS(int s){
            bool* visited = new bool[this->V];
            for(int i = 0; i < this->V; i++)
                visited[i] = false; 

            DfsUtil(s, visited);
            cout << endl;
        }
};

int main(){
    GraphTraversal g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.printGraph();
    g.BFS(2);
    g.DFS(2);
}