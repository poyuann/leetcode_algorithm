class Solution {
public:
    string removeDuplicates(string s, int k) {
        int i = 0, n = s.size();
        vector<int> cnt(n);
        for (int j = 0; j < n; ++j, ++i) {
            s[i] = s[j];
            cnt[i] = (i > 0 && s[i - 1] == s[i]) ? cnt[i - 1] + 1 : 1;
            if (cnt[i] == k) i -= k;
        }
        return s.substr(0, i);
    }
};
