class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        int c = 1;
        int b = -1;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1 && b == -1) {
                b = i;
                break;
            }
        }
        
        if (b == -1) {
            return 0;
        }
        
        for (int i = b; i < n; i++) {
            if (nums[i] == 1) {
                ans = (ans * 1LL * c) % (1000000000 + 7);
                c = 1;
            } else {
                c++;
            }
        }
        
        return ans;
    }
};
