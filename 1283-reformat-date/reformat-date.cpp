class Solution {
public:
    string reformatDate(string date) {
      int first=date.find(' ');
      int second=date.find(' ',first+1);
    string day = date.substr(0, first);
    string month = date.substr(first + 1, second - first - 1);
    string year = date.substr(second + 1);  
    day = day.substr(0, day.size() - 2);
     if(day.size() == 1)
            day = "0" + day;
            unordered_map<string, string> mp = {
            {"Jan", "01"},
            {"Feb", "02"},
            {"Mar", "03"},
            {"Apr", "04"},
            {"May", "05"},
            {"Jun", "06"},
            {"Jul", "07"},
            {"Aug", "08"},
            {"Sep", "09"},
            {"Oct", "10"},
            {"Nov", "11"},
            {"Dec", "12"}
        };
        return year + "-" + mp[month] + "-" + day;
    }
};