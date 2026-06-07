class Solution {
public:
int solve(vector<int>& prices){
    int n=prices.size();
vector<vector<int>>curr(2, vector<int>(3,0));
vector<vector<int>>next(2, vector<int>(3,0));
    for(int index=n-1;  index>=0; index--){
    for(int buy=0; buy<=1; buy++){
        for(int limit=1; limit<=2; limit++){
 int profit=0;
  if(buy){
    int buykro=-prices[index]+next[0][limit];
    int skipkro=0+next[1][limit];
    profit=max(buykro,skipkro);
  }
  else{
    int salekro=prices[index]+next[1][limit-1];
    int skipkro=0+next[0][limit];
    profit=max(salekro,skipkro);
  }
curr[buy][limit]=profit;

    }
    }
   next=curr;
 }
  return next[1][2];
}
    int maxProfit(vector<int>& prices) {
         return solve(prices);
    }
};