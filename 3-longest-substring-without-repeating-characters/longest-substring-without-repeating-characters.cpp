class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         vector<int> visited(256, 0);
        
        int left = 0, right = 0, maxLen = 0;

        while(right < s.size()) {
            if(visited[s[right]] == 0) {
                visited[s[right]] = 1;
                maxLen = max(maxLen, right - left + 1);
                right++;
            } else {
                visited[s[left]] = 0;
                left++;
            }
        }

        return maxLen;
    }
};