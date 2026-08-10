class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        for(int i = 0; i < nums.size() - 1; i++) {
            bool found = false;
            for(int k = i + 1; k <= nums.size() - 1; k++) {
                if(nums[k] > nums[i]) {
                    ans[i] = nums[k];
                    found = true;
                    break;
                }
            }
            if(!found) {
                for(int k = 0; k < i; k++) {
                    if(nums[k] > nums[i]) {
                        ans[i] = nums[k];
                        found = true;
                        break;
                    }
                }
            }
        }
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] > nums[nums.size() - 1]) {
                ans[nums.size() - 1] = nums[i];
                break;
            }
        }
        return ans;
    }
};