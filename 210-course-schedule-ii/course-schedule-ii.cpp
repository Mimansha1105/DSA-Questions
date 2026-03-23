class Solution {
public:
 bool dfs(int node, vector<vector<int>>& adj, 
             vector<int>& visited, stack<int>& s) {
        
 visited[node] = 1;

 for (auto nbr : adj[node]) {
 if (visited[nbr] == 0) {
if (dfs(nbr, adj, visited, s)) return true;
   }
 else if (visited[nbr] == 1) {
  return true; 
   }
  }
 visited[node] = 2;
 s.push(node);
 return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }
        vector<int> visited(numCourses, 0);
        stack<int> s;

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (dfs(i, adj, visited, s)) {
                    return {}; 
                }
            }
        }

        vector<int> ans;
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};