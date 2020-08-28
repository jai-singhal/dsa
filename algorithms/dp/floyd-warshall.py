from math import inf as INF

class FloyedWarshall():
    def __init__(self, graph, *args, **kwargs):
        self.graph = graph
        return super().__init__(*args, **kwargs)

    def run(self):
        pass


graph = [
    [0,5,INF,10], 
    [INF,0,3,INF], 
    [INF, INF, 0,   1], 
    [INF, INF, INF, 0] 
] 
fw = FloyedWarshall(graph)
fw.run(graph);