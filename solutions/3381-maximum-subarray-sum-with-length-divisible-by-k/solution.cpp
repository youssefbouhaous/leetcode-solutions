class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long int ans=0;
        int n=nums.size();
        for(int i=0;i<k;i++){
            ans+=nums[i];
        }
        vector<long long int>pre(n+1);
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+(long long int)nums[i];
        }
        vector<long long int>dp(n+1);
        for(int i=k-1;i<n;i++){
            dp[i]=max(pre[i+1]-pre[i+1-k],pre[i+1]-pre[i+1-k]+((i+1-k-1>=0)?dp[i+1-k-1]:0));
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};