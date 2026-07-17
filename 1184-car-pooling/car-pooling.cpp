class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>diff(1001, 0);
        for(auto &trip:trips){
            int passenger=trip[0];
            int from=trip[1];
            int to= trip[2];
            diff[from]+=passenger;
            diff[to]-=passenger;
        }
        int currpass=0;
        for(int i=0;  i<diff.size(); i++){
            currpass+=diff[i];
            if(currpass>capacity){
                return false;
                break;
            }     
               }
               return true;
    }
};