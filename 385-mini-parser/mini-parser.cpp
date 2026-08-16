class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s[0] != '[') {
            return NestedInteger(stoi(s));
        }
        stack<NestedInteger> st;
        int num = 0;
        bool negative = false;
        bool hasNum = false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '[') {
                st.push(NestedInteger());
            }
            else if (s[i] == '-') {
                negative = true;
            }
            else if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                hasNum = true;
            }
            else if (s[i] == ',' || s[i] == ']') {
                if (hasNum) {
                    if (negative)
                        num = -num;
                    st.top().add(NestedInteger(num));
                    num = 0;
                    negative = false;
                    hasNum = false;
                }
                if (s[i] == ']' && st.size() > 1) {
                    NestedInteger current = st.top();
                    st.pop();
                    st.top().add(current);
                }
            }
        }
        return st.top();
    }
};