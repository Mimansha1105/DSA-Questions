class Solution {
public:
unordered_map<string, string>mp;
int counter=0;
    string encode(string longUrl) {
        string id=to_string(counter++);
        mp[id]= longUrl;
        return "http://tinyurl.com/"+id;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string id=shortUrl.substr(shortUrl.find_last_of('/')+1);
        return mp[id];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));