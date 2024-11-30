class Solution {
    int dp[1005][105][2];
    int k;
    int f(int i,int a,bool b,vector<int>&p){
        if(i>=p.size()) return dp[i][a][b]=0;
        if(dp[i][a][b]!=-1) return dp[i][a][b];
        if(b){
            return dp[i][a][b]=max(p[i]+f(i+1,a,false,p),f(i+1,a,b,p));
        }
        else{
            if(a<k){
                return dp[i][a][b]=max(-p[i]+f(i+1,a+1,true,p),f(i+1,a,b,p));
            }
            else{
                return dp[i][a][b]=f(i+1,a,b,p);
            }
        }
    }
public:
    int maxProfit(int kk, vector<int>& prices) {
        k=kk;
        for(int i=0;i<1005;i++)
            for(int k=0;k<105;k++){
                dp[i][k][0]=-1;
                dp[i][k][1]=-1;
            }
        return f(0,0,false,prices);
    }
};