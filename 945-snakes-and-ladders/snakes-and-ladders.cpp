class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        auto getPos = [&](int num){
            int r = (num-1)/n;
            int c = (num-1)%n;
            int row = n-1-r;
            if(r%2)
                c = n-1-c;
            return pair<int,int>{row,c};
        };
        queue<int> q;
        vector<int> dist(n*n+1,-1);
        q.push(1);
        dist[1]=0;
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            if(cur==n*n)
                return dist[cur];
            for(int next=cur+1; next<=min(cur+6,n*n); next++){
                auto [r,c]=getPos(next);
                int dest = board[r][c]==-1 ? next : board[r][c];
                if(dist[dest]==-1){
                    dist[dest]=dist[cur]+1;
                    q.push(dest);
                }
            }
        }
        return -1;
    }
};