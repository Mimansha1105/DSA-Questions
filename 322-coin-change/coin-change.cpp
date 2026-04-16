class Solution {
public:
int solve(vector<int> &num, int x){
   int INF = 1e9;
   vector<int> dp(x+1, INF);

   dp[0]=0;
   for(int i=1; i<=x;i++ ){
    for(int j=0; j<num.size(); j++){
        if(i-num[j]>=0 && dp[i-num[j]!=INT_MAX]){
            dp[i]=min(dp[i], dp[i-num[j]]+1);
        }
    }
    
   }
      if(dp[x] == INF)
       return -1;
   else
       return dp[x];
  
}
    int coinChange(vector<int>& coins, int amount) {
      return solve(coins, amount);
    }
};