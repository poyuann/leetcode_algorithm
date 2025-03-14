class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            vector<int> ans;
            priority_queue<int, vector<int>, less<int> > q;
            map<int, int> mp;
            for (int i = 0; i < nums.size(); ++i) {
                q.push(nums[i]);
                mp[nums[i]] = i; 
                while (mp[q.top()] + k <= i) q.pop();
                if (i >= k - 1) ans.push_back(q.top()); 
            } 
            return ans;
        }
    };
    