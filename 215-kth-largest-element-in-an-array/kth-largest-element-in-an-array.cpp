class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        k = n - k + 1;
             priority_queue<int>pq;
     for(int i=0;i<k;i++){
         pq.push(nums[i]);
     }
     for(int i=k;i<nums.size();i++){
         if(nums[i]<pq.top()){
             pq.pop();
             pq.push(nums[i]);
         }
     }
     int ans=pq.top();
     return ans;
    }
};