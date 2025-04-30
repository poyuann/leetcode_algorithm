class Solution {
    public:
        vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
            vector<int> res(n), count(n);
            vector<vector<int>> tree(n);
            for (auto &edge : edges) {
                tree[edge[0]].push_back(edge[1]);
                tree[edge[1]].push_back(edge[0]);
            }
            helper(tree, 0, -1, count, res);
            helper2(tree, 0, -1, count, res);
            return res;
        }
        void helper(vector<vector<int>>& tree, int cur, int pre, vector<int>& count, vector<int>& res) {
            for (int i : tree[cur]) {
                if (i == pre) continue;
                helper(tree, i, cur, count, res);
                count[cur] += count[i];
                res[cur] += res[i] + count[i];
            }
            ++count[cur];
        }
        void helper2(vector<vector<int>>& tree, int cur, int pre, vector<int>& count, vector<int>& res) {
            for (int i : tree[cur]) {
                if (i == pre) continue;
                res[i] = res[cur] - count[i] + count.size() - count[i];
                helper2(tree, i, cur, count, res);
            }
        }
    };