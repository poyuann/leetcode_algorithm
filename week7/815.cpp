class Solution {
    public:
        int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
            if (source == target) return 0;
            int res = 0;
            unordered_map<int, vector<int>> stop2bus;
            queue<int> q{{source}};
            unordered_set<int> visited;
            for (int i = 0; i < routes.size(); ++i) {
                for (int j : routes[i]) {
                    stop2bus[j].push_back(i);
                }
            }
            while (!q.empty()) {
                ++res;
                for (int i = q.size(); i > 0; --i) {
                    int t = q.front(); q.pop();
                    for (int bus : stop2bus[t]) {
                        if (visited.count(bus)) continue;
                        visited.insert(bus);
                        for (int stop : routes[bus]) {
                            if (stop == target) return res;
                            q.push(stop);
                        }
                    }
                }
            }
            return -1;
        }
    };