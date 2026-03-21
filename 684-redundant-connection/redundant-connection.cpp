class Solution {
public:

bool iscyclicbfs(int src,
                 unordered_map<int, bool> &visited,
                 unordered_map<int, list<int>> &adj) {

    unordered_map<int, int> parent;
    queue<int> q;

    q.push(src);
    visited[src] = true;
    parent[src] = -1;

    while (!q.empty()) {
        int frontnode = q.front();
        q.pop();

        for (auto i : adj[frontnode]) {

            if (visited[i] && i != parent[frontnode]) {
                return true;
            }

            else if (!visited[i]) {
                visited[i] = true;
                parent[i] = frontnode;
                q.push(i);
            }
        }
    }
    return false;
}


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
           unordered_map<int, list<int>> adj;

    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];

     
        adj[u].push_back(v);
        adj[v].push_back(u);

        unordered_map<int, bool> visited;

        
        if (iscyclicbfs(u, visited, adj)) {
            return edge; 
        }
    }

    return {};
    }
};