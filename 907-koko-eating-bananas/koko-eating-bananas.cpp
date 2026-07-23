class Solution {
public:

bool possible (vector<int>& piles, int h, int k){
    long long hours=0;
    for(int pile: piles){
        hours+=ceil((double)pile/k);
    }
    return hours<=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=0;
        for(int i=0; i<piles.size(); i++){
            high=max(high, piles[i]);
        }
        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(piles,h,mid)){
             ans=min(ans,mid);
            high=mid-1;
            }
            else{
         
         low=mid+1;
            }
        }
        return ans;
    }
};