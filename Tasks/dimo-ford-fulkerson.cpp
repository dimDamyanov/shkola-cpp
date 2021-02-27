#include <iostream>
#include <vector>
#include <utility>
#include <queue>

int n, m;
std::vector<std::vector<std::pair<int, int>>> v;
std::vector<int> parent;
std::vector<bool> visited;

bool bfs() {
    std::queue<int> q;
    q.push(0);
    visited.clear();
    visited.resize(n);
    while (!q.empty()) {
        auto f = q.front();
        q.pop();
        visited[f] = true;

        for (auto &x: v[f]) {
            if (!visited[x.first] && x.second > 0) {
                q.push(x.first);
                parent[x.first] = f;
            }
        }
    }
    
    return visited[n - 1];
}

int main() {
    std::cin >> n >> m;
    v.resize(n);
    parent.resize(n);
    visited.resize(n);

    for (int i = 0; i < m; i++) {
        int f, t, w;
        std::cin >> f >> t >> w;
        v[f].push_back({t, w});
        v[t].push_back({f, 0});
    }

    int max_flow = 0;
    while (bfs()) {
        int curr = n - 1;
        unsigned curr_flow = -1;
        while (curr != 0) {
            int curr_edge;
            for (int i = 0; i < v[parent[curr]].size(); i++) {
                auto x = v[parent[curr]][i];
                if (x.first == curr) {
                    curr_edge = i;
                    break;
                }
            }
            curr_flow = std::min(curr_flow, (unsigned) v[parent[curr]][curr_edge].second);
            curr = parent[curr];
        }
        
        curr = n - 1;
        while (curr != 0) {
            int curr_edge;
            for(int i = 0; i < v[parent[curr]].size(); i++) {
                auto x = v[parent[curr]][i];
                if (x.first == curr) {
                    curr_edge = i;
                    break;
                }
            }

            v[parent[curr]][curr_edge].second -= curr_flow;
            v[curr_edge][parent[curr]].second += curr_flow;
            curr = parent[curr];
        }

        max_flow += curr_flow;
    }

    std::cout << max_flow << std::endl;
    return 0;
}