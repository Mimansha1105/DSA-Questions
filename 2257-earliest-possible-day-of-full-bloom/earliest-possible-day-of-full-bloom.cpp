class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>>v;
        for(int i=0; i< plantTime.size(); i++){
            v.push_back({growTime[i],plantTime[i]});
        }
     sort(v.rbegin(), v.rend());
     int plant=0;
     int ans=0;
     for(int j=0; j<v.size(); j++){
  plant+= v[j].second;
  ans=max(ans, plant+v[j].first);
     }
     return ans;
    }
};