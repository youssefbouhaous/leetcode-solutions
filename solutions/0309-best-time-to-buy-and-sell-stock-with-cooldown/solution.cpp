class Solution {
    int dp[5005][2];
    int f(int i,int c,vector<int>& p){
        if(i>=p.size()) return dp[i][c]=0;
        if(dp[i][c]!=-1) return dp[i][c];
        if(c==1) return dp[i][c]=max(p[i]+f(i+2,0,p),f(i+1,1,p));
        return dp[i][c]=max(-p[i]+f(i+1,1,p),f(i+1,0,p));
    }
public:
    int maxProfit(vector<int>& p) {
        for(int i=0;i<5005;i++){
            dp[i][0]=-1;
            dp[i][1]=-1;
        }
        return f(0,0,p);
    }
};