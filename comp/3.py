class ParentNode:
    def __init__(self, data): 
        self.vertex = data
        self.value = 0 
        self.nodes = []

class Graph: 
    def __init__(self, vertices): 
        self.V = vertices
        self.graph = []
        for i in range(vertices+1):
            self.graph.append(ParentNode(i))
            
    def add_edge(self, src, dest): 
        self.graph[src].nodes.append(dest)
  
    def print_graph(self): 
        for i in range(1, self.V): 
            print(self.graph[i].value, end = " ")


N, Q =  [int(i) for i in input().split()]
graph = Graph(N+1) 
for i in range(N-1):
    a, b =  [int(i) for i in input().split()]
    graph.add_edge(a,b)    

for i in range(Q):
    a, b =  [int(i) for i in input().split()]
    temp = graph.graph[i].nodes
    graph.graph[a].value += b
        
for i in range(1, N+1):
    for t in graph.graph[i].nodes:
        graph.graph[t].value += graph.graph[i].value
        
graph.print_graph()