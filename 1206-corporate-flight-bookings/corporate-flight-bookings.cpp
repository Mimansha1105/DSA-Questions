class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>op;
        vector<int>diff(n+2,0);
        for(auto &b:bookings){
            int first = b[0];
            int last = b[1];
            int seats = b[2];

            diff[first] += seats;
            diff[last + 1] -= seats;
        }
        vector<int>ans(n);
        int curr = 0;
        for (int i = 1; i <= n; i++) {
            curr += diff[i];
            ans[i - 1] = curr;
        }
        return ans;
    }
};