#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) dfs(v);
    }
}

int main() {
    int N, E; // N = number of nodes, E = number of edges
    cin >> N >> E;

    adj.assign(N, {});
    visited.assign(N, false);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // for undirected graph
    }

    dfs(0); // start DFS from node 0

    bool connected = true;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) connected = false;
    }

    if (connected) cout << "Graph is connected\n";
    else cout << "Graph is not connected\n";

    return 0;
}
