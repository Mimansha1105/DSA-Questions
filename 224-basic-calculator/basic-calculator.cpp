class Solution {
public:
    int calculate(string s) {

        stack<long long> st;

        long long result = 0;
        long long num = 0;
        long long sign = 1;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + (s[i] - '0');
            }

            else if (s[i] == '+') {
                result += sign * num;
                num = 0;
                sign = 1;
            }

            else if (s[i] == '-') {
                result += sign * num;
                num = 0;
                sign = -1;
            }

            else if (s[i] == '(') {
                st.push(result);
                st.push(sign);

                result = 0;
                sign = 1;
            }

            else if (s[i] == ')') {
                result += sign * num;
                num = 0;

                long long previousSign = st.top();
                st.pop();

                long long previousResult = st.top();
                st.pop();

                result = previousResult + previousSign * result;
            }
        }

        result += sign * num;

        return result;
    }
};