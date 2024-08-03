class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int totalOnes = 0;
        for (int num : nums) {
            if (num == 1) {
                totalOnes++;
            }
        }
        if (totalOnes == 0) {
            return 0;
        }
        nums.insert(nums.end(), nums.begin(), nums.end());
        vector<int> prefixSum(2 * n + 1, 0);
        for (int i = 0; i < 2 * n; i++) {
            prefixSum[i + 1] = prefixSum[i] + 1 - nums[i];
        }
        int minSwaps = INT_MAX;
        for (int i = 0; i < n; i++) {
            int currentSwaps = prefixSum[i + totalOnes] - prefixSum[i];
            minSwaps = min(minSwaps, currentSwaps);
        }
        return minSwaps;
    }
};
