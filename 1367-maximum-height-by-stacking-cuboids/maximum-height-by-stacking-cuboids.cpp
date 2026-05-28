class Solution {
public:
bool  check(vector<int>base, vector<int>newbox){
if(newbox[1]<=base[1] && newbox[0]<=base[0] && newbox[2]<=base[2] )
return true;
else
return false;
}
    int solve(vector<vector<int>>& a, int &n) {

        vector<int> currow(n + 1, 0);
        vector<int> nexrow(n + 1, 0);

        for (int curr = n - 1; curr >= 0; curr--) {

            for (int prev = curr - 1; prev >= -1; prev--) {

                int take = 0;

                if (prev == -1 || check(a[curr] ,a[prev])) {
                    take = a[curr][2] + nexrow[curr + 1];
                }

                int nottake = nexrow[prev + 1];

                currow[prev + 1] = max(take, nottake);
            }

            nexrow = currow;
        }

        return nexrow[0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
     for(auto &a:cuboids){
        sort(a.begin(), a.end());
     }
     sort(cuboids.begin(), cuboids.end());
     int n=cuboids.size();
     return solve( cuboids ,n);
    }
};