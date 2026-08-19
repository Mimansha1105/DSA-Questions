class Solution {
public:
    string oddString(vector<string>& words) {
        vector<int> first = getDiff(words[0]);
        vector<int> second = getDiff(words[1]);
        if (first != second) {
            vector<int> third = getDiff(words[2]);
            if (first == third)
                return words[1];
            else
                return words[0];
        }
        for (int i = 2; i < words.size(); i++) {
            vector<int> curr = getDiff(words[i]);
            if (curr != first)
                return words[i];
        }
        return "";
    }
private:
    vector<int> getDiff(string s) {
        vector<int> diff;
        for (int i = 1; i < s.size(); i++) {
            diff.push_back(s[i] - s[i - 1]);
        }
        return diff;
    }
};