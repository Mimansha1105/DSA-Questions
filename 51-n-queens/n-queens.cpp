class Solution {
public:
 void addsolution(vector<vector<int>>& board, vector<vector<string>>& ans, int n){
        vector<string> temp;

        for(int i = 0; i < n; i++){
      string s = "";
          for(int j = 0; j < n; j++){
          if(board[i][j] == 1)
              s += 'Q';
           else
                    s += '.';
            }
            temp.push_back(s);
        }

        ans.push_back(temp);
    }

bool issafe(int row, int col ,vector<vector<int>>& board, int n ){
  //check for row
  int x=row; 
  int y=col;
  while(y>=0){
	  if(board[x][y]==1){
		  return false;
	  }
	  y--;
  }
// par checck for upar ka diagonal
  x=row;
  y=col;
  while(x>=0 && y>=0){
	   if(board[x][y]==1){
		  return false;
	  }
	 y--;
	 x--;
  }
//check for niche ka diagonal
    x=row;
  y=col;
  while(x<n && y>=0){
	   if(board[x][y]==1){
		  return false;
	  }
	 y--;
	 x++;
  }
   return true;
}

   void solve(int col, vector<vector<string>>&ans, vector<vector<int>>& board, int n){
	   if(col==n){
		   addsolution(board, ans, n);
		   return;
	   }
	   for(int row=0;row<n;row++){
		   if(issafe(row, col, board, n)){
			   board[row][col]=1;
			   solve(col+1, ans, board, n);
			   //backtrack yha ho riyaaa
			   board[row][col]=0;
		   }
	   }
   }




    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board(n, vector<int>(n,0));
	vector<vector<string>>ans;
	solve(0, ans, board, n);
	return ans;
    }
};