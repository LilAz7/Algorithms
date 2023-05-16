#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

#define INF INT_MAX // ���������� �������������

using namespace std;


// ��������� ��� ������������� �����
struct Edge {
    int to, weight;
    Edge(int to, int weight) {
        this->to = to;
        this->weight = weight;
    }
};

// ������� ��� ������ ����������� ���� � �����
void dijkstra(int start, vector<vector<Edge>>& graph, vector<int>& dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // ������������� ���������� �� ���� ������ ��������������
    for (int i = 0; i < graph.size(); i++) {
        dist[i] = INF;
    }
    // ���������� �� ��������� ������� ����� 0
    dist[start] = 0;
    pq.push(make_pair(dist[start], start));
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].to;
            int weight = graph[u][i].weight;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    // ������ ����� ��������� �������� ���������
    vector<vector<int>> adjacency_matrix = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };
    // �������� ����� �� ������ ������� ���������
    vector<vector<Edge>> graph(adjacency_matrix.size());
    for (int i = 0; i < adjacency_matrix.size(); i++) {
        for (int j = 0; j < adjacency_matrix[i].size(); j++) {
            if (adjacency_matrix[i][j] != 0) {
                graph[i].push_back(Edge(j, adjacency_matrix
                    [i][j]));
            }
        }
    }
    // ���������� ��������� ��������
    int start = 0;
    vector<int> dist(graph.size());
    dijkstra(start, graph, dist);
    // ����� �����������
    cout << "������� \t ���������� �� ���������\n";
    for (int i = 0; i < graph.size(); i++) {
        cout << i << "\t\t" << dist[i] << endl;
    }
    return 0;
}