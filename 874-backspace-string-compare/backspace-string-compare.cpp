class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string st1;
        string st2;
        for(int i=0; i<s.length();i++){
              if (s[i] != '#') {
                st1.push_back(s[i]);
            }
            else if (!st1.empty()) {
                st1.pop_back();
            }
        }
         for(int i=0; i<t.length();i++){
              if (t[i] != '#') {
                st2.push_back(t[i]);
            }
            else if (!st2.empty()) {
                st2.pop_back();
            }
        }
        return st1==st2;
    }
};