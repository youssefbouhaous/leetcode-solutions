class Solution {
    vector<int>dp;
    int n;
    int INF=1e9;
    int f(int i,vector<int>&nums){
        if(i==n-1) return 0;
        if(i>=n) return INF;
        if(dp[i]!=0) return dp[i];
        int steps=INF;
        for(int j=i+1;j<=nums[i]+i;j++){
            steps=min(steps,f(j,nums)+1);
        }
        return dp[i]=steps;
    }

public:
    int jump(vector<int>& nums) {
        n=nums.size();
        dp.resize(n,INF);
        dp[0]=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<min(i+nums[i]+1,n);j++){
                dp[j]=min(dp[j],dp[i]+1);
            }
        }
        return dp[n-1];
    }
};