// Title: Homework 4-2
// Abstract: Topological sorting assignment
// Name: Aaron Berkness
// Date: 10/1/24

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void topologicalSort(int vertices, int edges, vector<pair<int, int>> &graph) {
    vector<int> inDegree(vertices, 0);
    vector<vector<int>> adjList(vertices);

    for (const auto &edge : graph) {
        int u = edge.first;
        int v = edge.second;
        adjList[u].push_back(v);
        inDegree[v]++;
    }

    for (int i = 0; i < vertices; i++) {
        cout << "In-degree[" << i << "]: " << inDegree[i] << endl;
    }

    queue<int> q;

    for (int i = 0; i < vertices; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topoOrder;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topoOrder.push_back(u);

        for (int v : adjList[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    if (topoOrder.size() != vertices) {
        cout << "No Order: " << endl;
    } else {
        cout << "Order:";
        for (int i = 0; i < topoOrder.size(); i++) {
            if (i != 0) cout << "->";
            cout << topoOrder[i];
        }
        cout << endl;
    }
}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;

    vector<pair<int, int>> graph(edges);

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[i] = {u, v};
    }

    topologicalSort(vertices, edges, graph);

    return 0;
}

