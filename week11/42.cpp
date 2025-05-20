class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = (int)height.size() - 1, level = 0, res = 0;
        while (left < right) {
            int lower = height[(height[left] < height[right]) ? left++ : right--];
            level = max(level, lower);
            res += level - lower;
        }
        return res;
    }
};