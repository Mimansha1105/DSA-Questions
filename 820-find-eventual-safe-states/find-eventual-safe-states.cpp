class Solution {
public:
void dfs(int node, vector<int>&vis, stack<int>&st, vector<vector<int>>&adj){
        vis[node] = 1;
        for(auto nbr : adj[node]){
            if(!vis[nbr]){
                dfs(nbr, vis, st, adj);
            }
        }
        st.push(node);
    }   
    void revdfs(int node, vector<int>&vis, vector<vector<int>>&trans, vector<int>&component){
        vis[node] = 1;
        component.push_back(node);
        
        for(auto nbr : trans[node]){
            if(!vis[nbr]){
                revdfs(nbr, vis, trans, component);
            }
        }
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
         int n = graph.size();
        vector<int> vis(n, 0);
        stack<int> st;       
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, vis, st, graph);
            }
        }
        vector<vector<int>> trans(n);
        for(int i = 0; i < n; i++){
            vis[i] = 0;
            for(auto nbr : graph[i]){
                trans[nbr].push_back(i);
            }
        }
    
        vector<int> safe(n, 1); 
        
        while(!st.empty()){
            int top = st.top();
            st.pop(); 
            if(!vis[top]){
                vector<int> component;
                revdfs(top, vis, trans, component);         
                if(component.size() > 1){
                    for(auto node : component){
                        safe[node] = 0; 
                    }
                }
                else{
                    int node = component[0];
                    for(auto nbr : graph[node]){
                        if(nbr == node){
                            safe[node] = 0;
                        }
                    }
                }
            }
        }

queue<int> q;   
        for(int i = 0; i < n; i++){
            if(safe[i] == 0){
                q.push(i);
            }
        }     
        while(!q.empty()){
            int node = q.front();
            q.pop();        
            for(auto parent : trans[node]){
                if(safe[parent] == 1){
                    safe[parent] = 0;
                    q.push(parent);
                }
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(safe[i]) ans.push_back(i);
        }   
        return ans;
    }
};