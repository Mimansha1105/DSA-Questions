class Solution {
public:
 bool solve(vector<int> &nums, int n, int target) {
        
        vector<bool> prev(target + 1, false);
        vector<bool> curr(target + 1, false);
        prev[0] = true;
        curr[0] = true;
        if(nums[0] <= target) {
            prev[nums[0]] = true;
        }
        for(int index = 1; index < n; index++) {
            for(int sum = 0; sum <= target; sum++) {
                
                bool include = false;
                if(nums[index] <= sum) {
                    include = prev[sum - nums[index]];
                }
                bool exclude = prev[sum];
                curr[sum] = include || exclude;
            }
            prev = curr;
        }
        return prev[target];
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];
        }
        if(totalSum % 2 != 0) {
            return false;
        }
        int target = totalSum / 2;
        return solve(nums, nums.size(), target);
    }
};