class Solution {
    int dp[5005];
public:
    int change(int amount, vector<int>& coins) {
        for(int j=0;j<5005;j++)dp[j]=0;
        dp[0]=1;
        for(int j=0;j<coins.size();j++){
            for(int i=0;i<=amount;i++){
                if(i-coins[j]>=0){
                    dp[i]+=dp[i-coins[j]];
                }
            }
        }
        return dp[amount];
    }
};