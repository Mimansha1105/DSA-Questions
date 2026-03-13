class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int,int>s;
        for(auto i:nums){
            s[i]++;
        }
       int index=0;
       for(auto p:s){
        int num=p.first;
        int count=p.second;
  while(count--){
    nums[index++]=num;
  }
       }
     
    }
};