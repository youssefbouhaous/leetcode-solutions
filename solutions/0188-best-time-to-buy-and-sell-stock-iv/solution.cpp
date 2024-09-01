class Solution {
public:
    int dp[1005][105][3];
    vector<int>p;
    int k;
    int f(int i,int o,int c){
        if(i>=p.size() || o>=k) return dp[i][o][c]=0;
        if(dp[i][o][c]!=-1) return dp[i][o][c];
        if(c==0){
            return dp[i][o][c]=max(-p[i]+f(i+1,o,1),f(i+1,o,0));
        }
        return dp[i][o][c]=max(p[i]+f(i+1,o+1,0),f(i+1,o,1));
    }
    int maxProfit(int kk, vector<int>& prices) {
        p=prices;
        k=kk;
        for(int i=0;i<1005;i++){
            for(int j=0;j<105;j++){
                dp[i][j][0]=-1;
                dp[i][j][1]=-1;
                dp[i][j][2]=-1;
            }
        }
        return f(0,0,0);
    }
};