class Solution {
    int fe;
    vector<int>p;
    int dp[50005][2];
    int f(int i,int c){
        if(i>=p.size()){
            return dp[i][c]=0;
        }
        if(dp[i][c]!=-1) return dp[i][c];
        if(c==0){
            return dp[i][c]=max(-p[i]+f(i+1,1),f(i+1,0));
        }
        return dp[i][c]=max(-fe+p[i]+f(i+1,0),f(i+1,1));
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        fe=fee;
        p=prices;
        for(int i=0;i<50005;i++){
            dp[i][0]=-1;
            dp[i][1]=-1;
        }
        return f(0,0);
    }
};