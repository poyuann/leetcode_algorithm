class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int max_freq = 1;
        for (const int num : nums)
            max_freq = max(max_freq, ++count[num]);
        map<int, vector<int>> buckets;
        for (const auto& kv : count)
            buckets[kv.second].push_back(kv.first);
        vector<int> ans;
        for (int i = max_freq; i >= 1; --i) {
            auto it = buckets.find(i);
            if (it == buckets.end()) continue;
            ans.insert(ans.end(), it->second.begin(), it->second.end());
            if (ans.size() == k) return ans;
        }
        return ans;
    }
};