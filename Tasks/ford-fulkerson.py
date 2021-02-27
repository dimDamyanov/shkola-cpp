from collections import deque
 
class Graph: 
   
    def __init__(self,graph): 
        self.graph = graph 
        self.vertices_count = len(graph) 
   
    def bfs(self, root, target, parent): 
        visited = [False] * self.vertices_count 
        queue = deque() 
        queue.append(root) 
        visited[root] = True

        while queue: 
            u = queue.popleft() 
            for ind, val in enumerate(self.graph[u]): 
                if not visited[ind] and val > 0: 
                    queue.append(ind)
                    visited[ind] = True
                    parent[ind] = u

        return visited[target]
    

    def fordFulkerson(self, source, sink): 
        parent = [-1] * self.vertices_count
        max_flow = 0
        while self.bfs(source, sink, parent):
            path_flow = float("Inf")
            s = sink
            while(s != source):
                path_flow = min(path_flow, self.graph[parent[s]][s])
                s = parent[s]
            max_flow += path_flow
            v = sink
            while(v != source):
                u = parent[v]
                self.graph[u][v] -= path_flow
                self.graph[v][u] += path_flow
                v = parent[v]
        return max_flow 
  

graph_as_matrix = [
        [0, 11, 12, 0, 0, 0],
        [0, 0, 0, 12, 0, 0], 
        [0, 1, 0, 0, 11, 0], 
        [0, 0, 0, 0, 0, 19], 
        [0, 0, 0, 7, 0, 4], 
        [0, 0, 0, 0, 0, 0]] 
  
graph = Graph(graph_as_matrix) 
  
source = 0
sink = 5
   
print (graph.fordFulkerson(source, sink)) 
