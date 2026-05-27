class Solution {
public:
 int solve(vector<int>& arr, int &n){
          vector<int>currow(n+1,0);
          vector<int>nextrow(n+1, 0);
              for(int curr=n-1; curr>=0; curr--){
                  for(int prev=curr-1;prev>=-1; prev--){
                       int take=0;
                        if(prev==-1 || arr[curr]>arr[prev]){
                         take=1+nextrow[ curr+1];
                            }
          
                       int nottake=0+nextrow[prev+1];
                       currow[prev+1]= max(take,nottake);
                  }
                  nextrow=currow;
              }
              return nextrow[0];
    
  }
    int lengthOfLIS(vector<int>& nums) {
       int n=nums.size();
       return solve(nums,n);
    }
};