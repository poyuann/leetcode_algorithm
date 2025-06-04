class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        map<long long, int> m;
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i - j > indexDiff) m.erase(nums[j++]);
            auto a = m.lower_bound((long long)nums[i] - valueDiff);
            if (a != m.end() && abs(a->first - nums[i]) <= valueDiff) return true;
            m[nums[i]] = i;
        }
        return false;
    }
};