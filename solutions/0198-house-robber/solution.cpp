class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        if(n<3){
            return max(nums[0],nums[1]);
        }
        vector<int>dp(n);
        dp[0]=nums[0];
        dp[1]=nums[1];
        dp[2]=dp[0]+nums[2];
        for(int i=3;i<n;i++){
            dp[i]=nums[i]+max(dp[i-2],dp[i-1]-nums[i-1]);
        }
        return max(dp[n-1],dp[n-2]);
    }
};