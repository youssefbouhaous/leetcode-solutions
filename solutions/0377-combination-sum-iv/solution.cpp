class Solution {
    int dp[1001];
    int f(vector<int>& nums,int t){
        if(t<0) return 0;
        if(dp[t]!=-1) return dp[t];
        if(t==0){
            return dp[0]=1;
        }
        int ans=0;
        for(auto x:nums){
            ans+=f(nums,t-x);
        }
        return dp[t]=ans;
    }
public:
    int combinationSum4(vector<int>& nums, int t) {
        for(int i=0;i<1001;i++)dp[i]=-1;
        return f(nums,t);
    }
};