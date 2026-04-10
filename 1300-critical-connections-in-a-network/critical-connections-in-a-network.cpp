class Solution {
public:
void dfs(int node, int parent, int &timer,
             vector<int>& disc, vector<int>& low,
             unordered_map<int, bool> &vis,
             unordered_map<int, list<int>> &adj,
             vector<vector<int>> &result) {
        vis[node] = true;
        disc[node] = low[node] = timer++;
        for (auto nbr : adj[node]) {
            if (nbr == parent) continue;
            if (!vis[nbr]) {
                dfs(nbr, node, timer, disc, low, vis, adj, result);
                low[node] = min(low[node], low[nbr]);
                if (low[nbr] > disc[node]) {
                    result.push_back({node, nbr});
                }
            }
            else {
                low[node] = min(low[node], disc[nbr]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
         unordered_map<int, list<int>> adj;
          for (int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int timer = 0;
        vector<int> disc(n, -1);
        vector<int> low(n, -1);
        unordered_map<int, bool> vis;
        vector<vector<int>> result;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, -1, timer, disc, low, vis, adj, result);
            }
        }
        return result;
    }
};