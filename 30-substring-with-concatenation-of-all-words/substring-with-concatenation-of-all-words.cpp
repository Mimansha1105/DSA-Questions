class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;

        if(words.empty()) return ans;

        int wordLen = words[0].size();
        int numWords = words.size();

        unordered_map<string, int> target;

        for(auto &w : words)
            target[w]++;

        for(int offset = 0; offset < wordLen; offset++) {

            unordered_map<string, int> seen;

            int left = offset;
            int count = 0;

            for(int right = offset;
                right + wordLen <= s.size();
                right += wordLen) {

                string word = s.substr(right, wordLen);

                if(target.find(word) != target.end()) {

                    seen[word]++;
                    count++;

                    while(seen[word] > target[word]) {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    if(count == numWords) {
                        ans.push_back(left);

                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                }
                else {
                    seen.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }

        return ans;
    }
};