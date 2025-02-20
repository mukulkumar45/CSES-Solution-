#include <bits/stdc++.h>
using namespace std;

bool ans = false;

bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& parent, int parentNode) {
    vis[node] = 1;

    for (auto ne : adj[node]) {
        if (!vis[ne]) {
            parent[ne] = node;
            if (dfs(ne, adj, vis, parent, node)) {
                return true;
            }
        }
        else if (ne != parentNode) {
            ans = true;
            vector<int> cycle;
            int current = node;

            cycle.push_back(current);
            while (current != ne) {
                current = parent[current];
                cycle.push_back(current);
            }
            cycle.push_back(ne);
            reverse(cycle.begin(), cycle.end());

            cout << cycle.size() << endl;
            for (int i : cycle) {
                cout << i << " ";
            }
            cout << endl;
            return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> vis(n + 1, 0);
    vector<int> parent(n + 1, -1);

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (dfs(i, adj, vis, parent, -1)) {
                return 0;
            }
        }
    }

    if (!ans) {
        cout << "IMPOSSIBLE" << endl;
    }
}
