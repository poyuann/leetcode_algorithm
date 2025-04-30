class Solution {
    public:
        int eraseOverlapIntervals(vector<vector<int>>& intervals) {
            if (intervals.empty()) return 0;      
            sort(intervals.begin(), intervals.end());
            int res = 0, n = intervals.size(), endLast = intervals[0][1];
            for (int i = 1; i < n; ++i) {
                int t = endLast > intervals[i][0] ? 1 : 0;
                endLast = t == 1 ? min(endLast, intervals[i][1]) : intervals[i][1];
                res += t;
            }
            return res;
        }
    };