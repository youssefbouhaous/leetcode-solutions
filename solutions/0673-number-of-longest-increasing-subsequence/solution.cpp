class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>dp(n,{1,1});
        for(int i=n-1;i>-1;i--){
            int f=1;
            int s=0;
            int c=0;
            for(int j=n-1;j>i;j--){
                if(nums[i]<nums[j] && s<dp[j].second){
                    s=dp[j].second;
                    f=dp[j].first;
                }
                else if(nums[i]<nums[j] && s==dp[j].second){
                    f+=dp[j].first;
                }
            }
            dp[i].first=f;
            dp[i].second=s+1;
        }
        int ans=0;
        int c=0;
        for(int i=0;i<n;i++){
            if(c<dp[i].second){
                c=dp[i].second;
                ans=dp[i].first;
            }
            else if(c==dp[i].second){
                ans+=dp[i].first;
            }
        }
        return ans;
    }
};