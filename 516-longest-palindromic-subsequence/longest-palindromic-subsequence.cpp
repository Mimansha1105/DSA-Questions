class Solution {
public:
int solve(string &a, string &b){
   // vector<vector<int>>dp(a.length()+1, vector<int>(b.length()+1,0));o
   vector<int>curr(b.length()+1, 0);
   vector<int>next(b.length()+1, 0);
int ans=0;
for(int i=a.length()-1; i>=0; i--){
    for(int j=b.length()-1; j>=0; j--){
 if(i<=a.length() && j<=b.length()){
 if(a[i]==b[j])
ans=1+next[ j+1];
else{
    ans=max(next[j], curr[j+1]);
}
 }

 curr[j]=ans;
    }
    next=curr;
}
return next[0];
}
    int longestPalindromeSubseq(string s) {
        string revs=s;
         reverse(revs.begin(), revs.end());
        return solve(s, revs);
    }
};