class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>window;
        unordered_map<char,int>need;
        for(char c:t){
            need[c]++;
        }
        int left=0;
        int count=0;
        int start=0;
        int len=INT_MAX;
        for(int right=0; right<s.length(); right++){
            char c= s[right];
            window[c]++;
            if (need.count(c) && window[c] <= need[c])
            count++;
        
        while(count==t.length()){
            if(right-left+1<len){
                len=right-left+1;
                start=left;
            }
            char leftchar=s[left];
            window[leftchar]--;
              if (need.count(leftchar) &&
                    window[leftchar] < need[leftchar]) {
                    count--;
                }
                left++;
        }
        }
        if(len==INT_MAX)
        return "";

        return s.substr(start, len);
    }
};