class Solution {
public:
    string minimizeStringValue(string s) {
        vector<int> freq(26, 0);
        for(char c : s) {
            if(c != '?') {
                freq[c - 'a']++;
            }
        }
        vector<char>replacement;
          for(char c : s) {
            if(c == '?') {
                int mn = 0;
                for(int i = 1; i < 26; i++) {
                    if(freq[i] < freq[mn]) {
                        mn = i;
                    }
                }
                replacement.push_back('a' + mn);
                freq[mn]++;
            }
        }
     sort(replacement.begin(), replacement.end());
        int j = 0;
        for(char &c : s) {
            if(c == '?') {
                c = replacement[j++];
            }
        }
        return s;
    }
};