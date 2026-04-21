// Problem: Count Strongly Connected Components (Kosaraju)
// Name: Aditya Gautam

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void dfs1(int u, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st) {
        vis[u] = 1;

        for (int v : adj[u]) {
            if (!vis[v]) {
                dfs1(v, adj, vis, st);
            }
        }

        st.push(u);
    }

    void dfs2(int u, vector<vector<int>> &rev, vector<int> &vis) {
        vis[u] = 1;

        for (int v : rev[u]) {
            if (!vis[v]) {
                dfs2(v, rev, vis);
            }
        }
    }

    int kosaraju(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(V), rev(V);

        // Build graph
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            rev[v].push_back(u);
        }

        vector<int> vis(V, 0);
        stack<int> st;

        // Step 1: DFS
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs1(i, adj, vis, st);
            }
        }

        // Reset visited
        fill(vis.begin(), vis.end(), 0);

        int scc = 0;

        // Step 2 + 3
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (!vis[node]) {
                dfs2(node, rev, vis);
                scc++;
            }
        }

        return scc;
    }
};

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(2));

    for (int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    Solution obj;
    cout << obj.kosaraju(V, edges);

    return 0;
}