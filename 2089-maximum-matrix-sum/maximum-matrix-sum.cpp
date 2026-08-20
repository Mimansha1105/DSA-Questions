class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int negative=0;
        int mn=INT_MAX;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] < 0) {
                    negative++;
                }
                sum += abs(matrix[i][j]);
                mn = min(mn, abs(matrix[i][j]));
            }
        }
        if (negative % 2 == 0) {
            return sum;
        }
        return sum - 2LL * mn;
    }
};