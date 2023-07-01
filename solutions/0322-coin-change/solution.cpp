class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int INF=1000000000;
        vector<int>dp(amount+1,INF);
        dp[0]=0;
        for(auto y:coins){
            if(y<=amount)
            dp[y]=1;
        }
        for(int i=1;i<amount+1;i++){
            if(dp[i]==1)
                continue;
            else{
                int a=INF;
                for(auto y:coins){
                    if(i-y>0)
                    a=min(a,dp[i-y]);
                }
                dp[i]=a+1;
            }
        }
        if(dp[amount]>=INF){
            return -1;
        }
        else{
            return dp[amount];
        }
    }
};