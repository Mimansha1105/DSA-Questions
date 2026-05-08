class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<string> s;
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {  
                char num = board[i][j];
                if(num != '.') {  
                    string row = string(1, num) + " in row " + to_string(i);
                    string col = string(1, num) + " in col " + to_string(j);
                    string box = string(1, num) + " in box " + 
                            to_string(i/3) + "-" + to_string(j/3);
                    if(s.count(row) || s.count(col) || s.count(box))
                        return false;                  
                    s.insert(row);
                    s.insert(col);
                    s.insert(box);
                }
            }
        } 
        return true;
    }
};