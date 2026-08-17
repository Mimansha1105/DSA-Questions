class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int median = arr[(n - 1) / 2];
        int i = 0;
        int j = n - 1;
        vector<int> ans;
        while (k--) {
            int leftStrength = abs(arr[i] - median);
            int rightStrength = abs(arr[j] - median);
            if (leftStrength > rightStrength) {
                ans.push_back(arr[i]);
                i++;
            }
            else if (rightStrength > leftStrength) {
                ans.push_back(arr[j]);
                j--;
            }
            else {
                if (arr[i] > arr[j]) {
                    ans.push_back(arr[i]);
                    i++;
                }
                else {
                    ans.push_back(arr[j]);
                    j--;
                }
            }
        }
        return ans;
    }
};