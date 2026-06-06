class Solution {
public:
int solve(vector<int>& prices){
    int n=prices.size();
 //vector<vector<int>>dp(n+1, vector<int>(2,0));
 vector<int>curr(n+1,0);
vector<int>next(n+1,0);
 for(int index=n-1;  index>=0; index--){
    for(int buy=0; buy<=1; buy++){
 int profit=0;
  if(buy){
    int buykro=-prices[index]+curr[0];
    int skipkro=0+next[1];
    profit=max(buykro,skipkro);
  }
  else{
    int salekro=prices[index]+next[1];
    int skipkro=0+curr[0];
    profit=max(salekro,skipkro);
  }
  curr[buy]=profit;

    }
    next=curr;
 }
  return next[1];
}
    int maxProfit(vector<int>& prices) {
         return solve(prices);
    }
};