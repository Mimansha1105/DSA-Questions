class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
         unordered_map<int, vector<int>> s;
       for (int i = 0; i < nums.size(); i++) {
    s[nums[i]].push_back(i);
}
for (auto entry : s) {
    vector<int> indices = entry.second;

    for (int i = 1; i < indices.size(); i++) {
        int diff = indices[i] - indices[i - 1];

        if (diff <= k) {
            return true;
        }
    }
}

    return false;
    }
};