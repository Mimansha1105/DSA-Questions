class Solution {
public:
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    
    unordered_map<int, list<pair<int,int>>> adj;

    for(auto &i : times){
        int u = i[0];
        int v = i[1];
        int w = i[2];

        adj[u].push_back({v,w});
    }

    vector<int> dist(n+1, INT_MAX);

    set<pair<int,int>> st;

    dist[k] = 0;
    st.insert({0,k});

    while(!st.empty()){
        auto top = *(st.begin());
        int nodeDist = top.first;
        int topNode = top.second;

        st.erase(st.begin());

        for(auto neighbour : adj[topNode]){
            int nextNode = neighbour.first;
            int weight = neighbour.second;

            if(nodeDist + weight < dist[nextNode]){
                
                auto record = st.find({dist[nextNode], nextNode});
                if(record != st.end()){
                    st.erase(record);
                }

                dist[nextNode] = nodeDist + weight;
                st.insert({dist[nextNode], nextNode});
            }
        }
    }

    int ans = INT_MIN;
    for(int i=1; i<=n; i++){
        if(dist[i] == INT_MAX) return -1;
        ans = max(ans, dist[i]);
    }

    return ans;
}
};