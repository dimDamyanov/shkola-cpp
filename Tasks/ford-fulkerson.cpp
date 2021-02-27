#include <iostream>
#include <queue>
#include <climits>

const int V = 6;

bool bfs(int graph[V][V], int s, int t, int parent[]) {
    bool visited[V] = {false};
    std::queue <int> queue;
    queue.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!queue.empty()) {
        int u = queue.front();
        queue.pop();
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] > 0) {
                queue.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return visited[t];
}

int fordFulkerson(int graph[V][V], int s, int t) {
    int u, v;
    int graph1[V][V];
    for (u = 0; u < V; u++) {
        for (v = 0; v < V; v++)
            graph1[u][v] = graph[u][v];
    }

    int parent[V];
    int max_flow = 0;

    while (bfs(graph1, s, t, parent)) {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = std::min(path_flow, graph1[u][v]);
        }
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            graph1[u][v] -= path_flow;
            graph1[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    
    return max_flow;
}

int main() {
     int graph[V][V] = { 
        {0, 11, 12, 0, 0, 0}, 
        {0, 0, 0, 12, 0, 0}, 
        {0, 1, 0, 0, 11, 0}, 
        {0, 0, 0, 0, 0, 19}, 
        {0, 0, 0, 7, 0, 4}, 
        {0, 0, 0, 0, 0, 0} 
        }; 
  
    std::cout << fordFulkerson(graph, 0, 5) << std::endl; 
  
    return 0; 
}