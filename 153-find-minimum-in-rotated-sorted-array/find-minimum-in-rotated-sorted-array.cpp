class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        int minimum=INT_MAX;
        while(s <= e){
            int mid = s + (e-s)/2;
    if(nums[s] <= nums[mid]){
       minimum=min(minimum,nums[s]);
       s=mid+1;
    }
    else{
minimum= min(minimum,nums[mid]);
e=mid-1;
    }
}
return minimum;
    }
};