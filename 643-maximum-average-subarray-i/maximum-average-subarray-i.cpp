class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans=0;
        int total=0;
      for(int i=0; i<k ; i++){
        total+=nums[i];
      }
      int maxtotal=total;
      for(int i=k; i<nums.size(); i++){
        total+=nums[i];
        total-=nums[i-k];
        maxtotal=max(maxtotal,total);
      }
      return (double)maxtotal/k;
    }
};