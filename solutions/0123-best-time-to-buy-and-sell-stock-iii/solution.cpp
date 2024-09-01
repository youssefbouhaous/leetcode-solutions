class Solution {
    int fe;
    vector<int>p;
    int dp[100005][2][3];
    int f(int i,int c,int o){
        if(i>=p.size() || o>=2) return dp[i][c][o]=0;
        if(dp[i][c][o]!=-1) return dp[i][c][o];
        if(c==0){
            return dp[i][c][o]=max(-p[i]+f(i+1,1,o),f(i+1,0,o));
        }
        return dp[i][c][o]=max(p[i]+f(i+1,0,o+1),f(i+1,1,o));
    }
public:
    int maxProfit(vector<int>& prices) {
        for(int i=0;i<100005;i++){
            dp[i][0][0]=-1;
            dp[i][0][1]=-1;
            dp[i][0][2]=-1;
            dp[i][1][0]=-1;
            dp[i][1][1]=-1;
            dp[i][1][2]=-1;
        }
        p=prices;
        return f(0,0,0);
    }
};