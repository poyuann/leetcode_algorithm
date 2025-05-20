class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size(), res = n * n;
        vector<vector<int>> dp(1 << n, vector<int>(n, n * n));
        for (int i = 0; i < n; ++i) dp[1 << i][i] = 0;
        for (int cur = 0; cur < (1 << n); ++cur) {
            bool repeat = true;
            while (repeat) {
                repeat = false;
                for (int i = 0; i < n; ++i) {
                    int dist = dp[cur][i];
                    for (int next : graph[i]) {
                        int path = cur | (1 << next);
                        if (dist + 1 < dp[path][next]) {
                            dp[path][next] = dist + 1;
                            if (path == cur) repeat = true;
                        }
                    }
                }
            }
        }
        for (int num : dp.back()) {
            res = min(res, num);
        }
        return res;
    }
};
