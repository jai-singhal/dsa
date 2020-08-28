#include<iostream>
#include<vector>

using namespace std;

struct node{
    int name;
};

struct AdjNode{
    int dist;
    bool visited;
};

struct Graph{
    vector<AdjNode> adj;
};


int djiskstra(int M, Graph* G){
    vector<int> djStack;

    for (int i = 1; i <= M; i++){
        for(int j = 0; j < G[i].adj.size(); j++){
            if(G[i].adj[j].visited == false){
                G[i].adj[j].visited = true;
                djStack.push_back(G[i].adj[j].name);
                if(G[i].adj[j].dist < G[])
            }
                
        }
    }
    
}

int main(){
    int N,M, x, y;
    cin >> N >> M;
    Graph G[M];
    for(int i = 1; i <= M; i++){
        node newNode;
        cin >> x;
        cin >> newNode.name;
        newNode.dist = 0;
        G[x].adj.push_back(newNode);
    }

    // for (int i = 0; i < M; i++){
    //     cout << i << "->" ;
    //     for(int j = 0; j < G[i].adj.size(); j++){
    //         cout << G[i].adj[j].name << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}