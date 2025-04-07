class Solution {
    public:
        vector<vector<int>> permute(vector<int>& nums) {
            const int N = nums.size();
            vector<vector<int>> res;
            vector<int> path;
            vector<int> visited(N, 0);
            dfs(nums, 0, visited, res, path);
            return res;
        }
    private:
        void dfs(vector<int>& nums, int pos, vector<int>& visited, vector<vector<int>>& res, vector<int>& path) {
            const int N = nums.size();
            if (pos == N) {
                res.push_back(path);
                return;
            }
            for (int i = 0; i < N; i++) {
                if (!visited[i]) {
                    visited[i] = 1;
                    path.push_back(nums[i]);
                    dfs(nums, pos + 1, visited, res, path);
                    path.pop_back();
                    visited[i] = 0;
                }
            }
        }
    };
    