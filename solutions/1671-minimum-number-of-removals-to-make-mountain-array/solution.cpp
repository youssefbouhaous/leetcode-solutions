class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> ls(n, 1), rs(n, 1);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    ls[i] = max(ls[i], ls[j] + 1);
                }
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j > i; --j) {
                if (nums[j] < nums[i]) {
                    rs[i] = max(rs[i], rs[j] + 1);
                }
            }
        }
        
        int ans = n;
        for (int i = 1; i < n - 1; ++i) {
            if (ls[i] > 1 && rs[i] > 1) {
                ans = min(ans, n - (ls[i] + rs[i] - 1));
            }
        }
        
        return ans;
    }
};
