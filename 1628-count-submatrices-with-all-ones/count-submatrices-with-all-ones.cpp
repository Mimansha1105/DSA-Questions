class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
          int m = mat.size();
        int n = mat[0].size();
        vector<int> height(n, 0);
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1)
                    height[j]++;
                else
                    height[j] = 0;
            }
            for (int j = 0; j < n; j++) {
                if (height[j] == 0)
                    continue;
                int mn = height[j];
                for (int k = j; k >= 0 && height[k] > 0; k--) {
                    mn = min(mn, height[k]);
                    ans += mn;
                }
            }
             }

        return ans;
    }
};