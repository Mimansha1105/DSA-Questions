class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
         int n = points.size();

        vector<int> key(n, INT_MAX);
        vector<bool> mst(n, false);

        key[0] = 0;
        int result = 0;
for(int i = 0; i < n; i++) {
   int mini = INT_MAX;
 int u = -1;

   for(int v = 0; v < n; v++) {
     if(!mst[v] && key[v] < mini) {
                    mini = key[v];
                    u = v;
                }
            }
              mst[u] = true;
            result += key[u];
            for(int v = 0; v < n; v++) {
                if(!mst[v]) {
                    int dist = abs(points[u][0] - points[v][0]) +
                               abs(points[u][1] - points[v][1]);

                    if(dist < key[v]) {
                        key[v] = dist;
                    }
                }
            }
        }

        return result;
    }
};