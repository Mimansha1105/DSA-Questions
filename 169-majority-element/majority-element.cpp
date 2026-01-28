class Solution {
public:
    int majorityElement(vector<int>& nums) {
      unordered_map<int,int>s;
        for(int i=0;i<nums.size();i++){
    s[nums[i]]++;
        }
        int maxcount=0;
        int ans;
        for (auto it : s){
            if(it.second>maxcount){
                maxcount=it.second;
                ans=it.first;
            }
        }
   return ans;
    }
};