class Solution {
public:
int solve(vector<int>& nums, int n, vector<int>& dp){
        if(n < 0) return 0;
 if(n == 0) return nums[0];
          if(dp[n] != -1) return dp[n];

        int incl = solve(nums, n-2, dp) + nums[n];
        int excl = solve(nums, n-1, dp);

        return dp[n] = max(incl, excl);
    }

int helper(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(nums, n-1, dp);
    }

    int rob(vector<int>& nums) {
         int n = nums.size();
           if(n == 1) return nums[0];
            vector<int> temp1(nums.begin(), nums.end()-1);
              vector<int> temp2(nums.begin()+1, nums.end());
                 return max(helper(temp1), helper(temp2));
    }
};