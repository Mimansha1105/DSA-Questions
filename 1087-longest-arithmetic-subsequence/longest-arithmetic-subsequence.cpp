class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int ans=0;
             int n=nums.size();
       if(n<=2)
       return n;
       unordered_map<int,int>dp[n+1];
       for(int i=1; i<n; i++){
           for(int j=0; j<i; j++){
               int diff=nums[i]-nums[j];
               dp[i][diff] = dp[j].count(diff)
                                ? dp[j][diff] + 1
                                : 2;

                
               ans=max(ans, dp[i][diff]);
           }
       
       } 
       return ans; 
    }
};