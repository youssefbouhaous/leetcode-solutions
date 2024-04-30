class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int m=*max_element(coins.begin(),coins.end());
        vector<int>dp((amount+1),-1);
        dp[0]=0;
        for(auto x:coins){
            if(x<=amount)
            dp[x]=1;
        }
        for(int i=1;i<=amount;i++){
            for(auto x:coins){
                if(i>=x){
                    if(dp[i]==-1){
                        if(dp[i-x]!=-1)
                        dp[i]=dp[i-x]+1;
                    }
                    else{
                        if(dp[i-x]!=-1)
                        dp[i]=min(dp[i],dp[i-x]+1);
                    }
                }
            }
        }
        return dp[amount];
    }
};