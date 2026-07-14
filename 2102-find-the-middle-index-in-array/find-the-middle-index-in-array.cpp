class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size();
        int total=0;
        for(int x:nums)
        total+=x;

        int leftsum=0;
        for(int i=0;i<n; i++){
            int rightsum=total-leftsum-nums[i];

            if(rightsum==leftsum)
            return i;

            leftsum+=nums[i];
        }
        return -1;
    }
};