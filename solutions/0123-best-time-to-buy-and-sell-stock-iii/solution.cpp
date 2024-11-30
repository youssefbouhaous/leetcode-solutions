class Solution {
    int dp[100005][3][2];
    int f(int i,int a,bool b,vector<int>&p){
        if(i>=p.size()) return dp[i][a][b]=0;
        if(dp[i][a][b]!=-1)return dp[i][a][b];
        if(b){
            return dp[i][a][b]=max(p[i]+f(i+1,a,false,p),f(i+1,a,b,p));
        }
        else{
            if(a<2){
                return dp[i][a][b]=max(-p[i]+f(i+1,a+1,true,p),f(i+1,a,b,p));
            }
            else{
                return dp[i][a][b]=f(i+1,a,b,p);
            }
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        for(int i=0;i<100005;i++){
            dp[i][0][0]=-1;
            dp[i][0][1]=-1;
            dp[i][1][0]=-1;
            dp[i][1][1]=-1;
            dp[i][2][0]=-1;
            dp[i][2][1]=-1;
        }
        return f(0,0,false,prices);
    }
};