class Solution {
public:
    int f(int i,int j,string&a,string&b,vector<vector<int>>&dp){
        if(i==a.size() || j==b.size()){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(a[i]==b[j]){
            if(j==b.size()-1) return dp[i][j]=1+f(i+1,j,a,b,dp);
            else{
                return dp[i][j] = f(i+1,j+1,a,b,dp)+f(i+1,j,a,b,dp);
            }
        }
        else{
            return dp[i][j]=f(i+1,j,a,b,dp);
        }
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(0,0,s,t,dp);
    }
};