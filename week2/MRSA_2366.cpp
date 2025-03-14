class Solution {
    public:
        long long minimumReplacement(vector<int>& nums) {
            int n = nums.size();
            int right = nums[n-1];
            long res = 0;
    
            for(int i = n-2; i >= 0; i--) {
                if(nums[i] > right) {
                    int splitCnt = (nums[i] - 1) / right;
                    right = nums[i] / (splitCnt + 1);
                    res += splitCnt;
                } else {
                    right = nums[i];
                }
            }
            return res;
        }
    };