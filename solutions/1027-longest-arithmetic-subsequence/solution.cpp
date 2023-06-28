
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,2));
        vector<int>id(20000,-1);
        int ans=2;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(-nums[j]+2*nums[i]<0 || id[-nums[j]+2*nums[i]]==-1) continue;
                dp[i][j]=dp[id[2*nums[i]-nums[j]]][i]+1;
                ans=max(ans,dp[i][j]);
            }
            id[nums[i]]=i;
        }
        return ans;
    }
};