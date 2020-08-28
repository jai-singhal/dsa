/*
Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that 
for every directed edge uv, vertex u comes before v in the ordering. 
Topological Sorting for a graph is not possible if the graph is not a DAG.


Time Complexity: The above algorithm is simply DFS with an extra stack. 
So time complexity is same as DFS which is O(V+E).

*/


#include "directed_graph.cpp"
#include<stack>

class GraphSort : public DirectedGraph{
    public:
        GraphSort(int v): DirectedGraph(v){}

        void topolgicalSortUtil(bool* visited, int start, stack<int> &s){
            visited[start] = true;
            
            list<int>::iterator it;
            for(it = this->adj[start].begin(); it != this->adj[start].end(); it++){
                if( !visited[*it]){
                    topolgicalSortUtil(visited, *it, s);
                }
                    
            }
            s.push(start); 
        }
        
        void topolgicalSort(){
            bool visited[this->V];
            stack<int> s;

            for(int i = 0; i < this->V; i++)
                visited[i] = false;

            for(int i = 0; i < this->V; i++){
                if ( !visited[i])
                    topolgicalSortUtil(visited, i, s);
            }   
                    
            while(!s.empty()){
                cout << s.top() << " ";
                s.pop();
            } 
            cout << endl;
        }

        void allPossibleTopolgicalSort(){
            bool visited[this->V];
            stack<int> s;

            for(int i = 0; i < this->V; i++)
                visited[i] = false;

            for(int i = 0; i < this->V; i++){
                if ( !visited[i])
                    topolgicalSortUtil(visited, i, s);
            }   
                    
            while(!s.empty()){
                cout << s.top() << " ";
                s.pop();
            } 
            cout << endl;
            
        }

};

int main(){

    GraphSort g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
 
    cout << "Following is a Topological Sort of the given graph: ";
    g.topolgicalSort();
 
    return 0;
}
    