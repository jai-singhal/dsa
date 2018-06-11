/*


*/

#include "../unidi_with_wt_graph.cpp"
#include <vector>
#include <algorithm>
#include <climits>

struct Item{
    int vertex;
    int dist;
};

class BinaryMinHeap{
    public:
        Item* arr;
        int capacity = 0, size = 0;
    public:
        BinaryMinHeap(int capacity = 20){
            this->capacity = capacity;
            arr = new Item[capacity];
        }
  
        void swap(Item &a, Item &b){
            Item temp = a;
            a = b;
            b = temp;
        }

        int left(int i){
            return 2*i+1;
        }

        int right(int i){
            return 2*i+2;
        }

        int parent(int i){
            return i/2;
        }

        Item getMinItem(){
            return (this->arr[0]);
        }
        
        int getMinWt(){
            return this->arr[0].dist;
        }   

        bool empty(){
            return this->size == 0;
        }   
        
        void insert(int vertex, int wt){
            if(this->size > this->capacity){
                cout << "Heap overflow" << endl;
                return;
            }
            this->size++;
            int i = this->size - 1;
            Item* newNode = new Item;
            newNode->dist = wt;
            newNode->vertex = vertex;
            arr[i] =  *newNode;
            while(i != 0 && this->arr[parent(i)].dist > this->arr[i].dist){
                swap(this->arr[i], this->arr[parent(i)]);
                i = parent(i);
            }
        }

        void minHeapify(int i){
            int l = left(i);
            int r = right(i);
            int smallest = i;
            if(l < this->size && this->arr[l].dist < this->arr[smallest].dist)
                smallest = l;
            if(r < this->size && this->arr[r].dist < this->arr[smallest].dist)
                smallest = r;
            if(i!=smallest){
                swap((this->arr[i]), (this->arr[smallest]));
                minHeapify(smallest);
            }      
        }

        Item extractMin(){
            this->size--;
            if(size == 1){
                return this->arr[0]; 
            }
            
            Item temp = this->arr[0];
            this->arr[0] = this->arr[this->size];
            minHeapify(0);   
            return temp;            
        }

        bool is_available(int v){
            for(int i = 0; i < this->size; i++){
                if(arr[i].vertex == v)
                    return true;
            }
            return false;
        }

        int get_index(int v){
            for(int i = 0; i < this->size; i++){
                if(arr[i].vertex == v)
                    return i;
            }
            return -1;
        }
};

class PathFinding: public UndirectedWeightedGraph, public BinaryMinHeap{
    public:
        PathFinding(int v): UndirectedWeightedGraph(v), BinaryMinHeap(v)
        {}

        int dist;
        BinaryMinHeap createMinHeap(){
            BinaryMinHeap minHeap(this->V);
            for(int i = 0; i < this->V; i++){
                if(i == 0) // change to source Item; taken 0 as default source
                    dist = 0;
                else
                    dist =  INT_MAX;
                minHeap.insert(i, dist);
            }
            return minHeap;
        }

        void minWtPath(){
            BinaryMinHeap minHeap = createMinHeap();
            list<Node> :: iterator it;
            
            while(!minHeap.empty()){
                Item u = minHeap.extractMin();
                cout << u.vertex  << endl;
                for(it = this->adj[u.vertex].begin(); it != this->adj[u.vertex].end(); it++){
                    int v = (*it).vertex;
                    int ind = minHeap.get_index(v);
                    if ( ind != -1 && minHeap.is_available(v) && 
                            u.dist + (*it).weight < minHeap.arr[ind].dist ){
                        if(minHeap.arr[ind].dist == INT_MAX)
                            minHeap.arr[ind].dist = (*it).weight;
                        else
                            minHeap.arr[ind].dist += (*it).weight;                              
                    }
                }
            }
            printWeights(minHeap);
        }

        void printWeights(BinaryMinHeap minHeap){   
            cout << this->V << endl; 
            for(int i = 0; i < this->V; i++){
                cout << minHeap.arr[i].vertex << " -> " << minHeap.arr[i].dist << endl;
            }
        }

};

int main(){
    PathFinding G = PathFinding(4);

    G.addEdge(0, 1, 10);
    G.addEdge(0, 2, 20);
    G.addEdge(2, 3, 20);
    G.addEdge(1, 3, 16);
    G.addEdge(1, 2, 5);
    G.addEdge( 0, 7, 8);
    G.addEdge( 1, 2, 8);
    G.addEdge( 1, 7, 11);
    G.addEdge( 2, 3, 7);
    G.addEdge( 2, 8, 2);
    G.addEdge( 2, 5, 4);
    G.addEdge( 3, 4, 9);
    G.addEdge( 3, 5, 14);
    G.addEdge( 4, 5, 10);
    G.addEdge( 5, 6, 2);
    G.addEdge( 6, 7, 1);
    G.addEdge( 6, 8, 6);
    G.addEdge( 7, 8, 7);

    G.minWtPath();
    // G.printWeights();

    return 0;
}