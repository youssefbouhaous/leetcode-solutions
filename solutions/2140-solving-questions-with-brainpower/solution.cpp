class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long>dp(n+1,0);
        for(int i=n-1;i>-1;i--){
            dp[i]=questions[i][0];
            if(questions[i][1]+1<n-i){
                dp[i]+=dp[i+questions[i][1]+1];
            }
            dp[i]=max(dp[i],dp[i+1]);
        }
        return dp[0];
    }
};