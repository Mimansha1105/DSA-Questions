class Solution {
public:
    string convert(string s, int numrows) {
          if(numrows == 1 || s.length() <= numrows) return s;

        vector<string> rows(numrows);
        int currrow = 0;
        bool goingdown = false;
         for(char c : s) {
        rows[currrow] += c;

            if(currrow == 0 || currrow == numrows - 1)
                goingdown = !goingdown;

            currrow += goingdown ? 1 : -1;
        }
        string result = "";
        for(string row : rows)
            result += row;

        return result;
    }
};