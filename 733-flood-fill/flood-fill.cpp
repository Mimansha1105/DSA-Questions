class Solution {
public:
void dfs(int sr, int sc,vector<vector<int>>& image, int oldcolor, int newcolor ){
    int n=image.size();
    int m= image[0].size();
    if(sr < 0 || sc < 0 || sr>= n || sc >= m || image[sr][sc] != oldcolor)
   return;
   image[sr][sc]=newcolor;
   dfs(sr+1, sc, image, oldcolor, newcolor);
      dfs(sr-1, sc, image, oldcolor, newcolor);
         dfs(sr, sc+1, image, oldcolor, newcolor);
            dfs(sr, sc-1, image, oldcolor, newcolor);


}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldcolor= image[sr][sc];
        if(oldcolor==color) return image;
        dfs(sr, sc,image, oldcolor, color);
        return image;
    }
};