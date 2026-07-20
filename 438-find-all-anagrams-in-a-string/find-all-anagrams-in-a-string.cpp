class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
     vector<int>freq(26,0);
     vector<int>window(26,0);
     for(char ch:p){
        freq[ch-'a']++;
     }  
     vector<int>ans;
     int left=0;
     for(int right=0; right<s.size(); right++){
        window[s[right]-'a']++;
        if(right-left+1 >p.size()){
            window[s[left]-'a']--;
            left++;
        }
        if(window==freq){
            ans.push_back(left);
        }
     } 
     return ans;
    }
};