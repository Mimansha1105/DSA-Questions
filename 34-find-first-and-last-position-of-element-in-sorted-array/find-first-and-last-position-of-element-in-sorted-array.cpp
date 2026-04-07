class Solution {
public:
 int findfirst(vector<int>& nums, int target) {
 int low = 0, high = nums.size() - 1;
 int ans = -1; 
 while(low <= high) {
  int mid = (low + high) / 2;
            
 if(nums[mid] == target) {
   ans = mid;
 high = mid - 1; 
   }
 else if(nums[mid] < target)
   low = mid + 1;
 else
   high = mid - 1;
  }
  return ans;
    }

     int findlast(vector<int>& nums, int target) {
 int low = 0, high = nums.size() - 1;
 int ans = -1; 
 while(low <= high) {
  int mid = (low + high) / 2;
            
 if(nums[mid] == target) {
   ans = mid;
 low = mid + 1; 
   }
 else if(nums[mid] < target)
   low = mid + 1;
 else
   high = mid - 1;
  }
  return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
         int first = findfirst(nums, target);
        int last = findlast(nums, target);
        
        return {first, last};
    }
};