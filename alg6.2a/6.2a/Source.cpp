#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<vector<int>>& graph, vector<bool>& visited, int u) {
    visited[u] = true;
    int count = 1;
    for (int v = 0; v < graph.size(); v++) {
        if (graph[u][v] && !visited[v]) {
            count += dfs(graph, visited, v);
        }
    }
    return count;
}

int connectivity(vector<vector<int>>& graph) {
    vector<bool> visited(graph.size(), false);
    visited[0] = true;
    int count = 1;
    for (int u = 0; u < graph.size(); u++) {
        if (!visited[u]) {
            count++;
            count += dfs(graph, visited, u);
        }
    }
    return count;
}

int main() {
    vector<vector<int>> graph = {
        {0, 1, 1, 0, 0, 0, 0},
        {1, 0, 1, 1, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {0, 1, 1, 0, 1, 1, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 1, 1, 0, 1},
        {0, 0, 0, 0, 1, 1, 0}
    };
    int count = connectivity(graph);
    cout << "Connectivity: " << count << endl; 
    return 0;
}