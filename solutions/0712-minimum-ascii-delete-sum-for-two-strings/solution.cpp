class Solution {
public:
    map<int,int>da;
    map<int,int>db;
    int f(int i,int j,string&s1,string&s2,vector<vector<int>>&dp){
        if(i==s1.size() || j==s2.size()){
            return max(da[s1.size()-1]-da[i-1],db[s2.size()-1]-db[j-1]);
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]=f(i+1,j+1,s1,s2,dp);
        else{
            return dp[i][j]=min(s1[i]+f(i+1,j,s1,s2,dp),s2[j]+f(i,j+1,s1,s2,dp));
        }
    }
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        da[0]=s1[0];
        db[0]=s2[0];
        for(int i=1;i<n;i++){
            da[i]=da[i-1]+s1[i];
        }
        for(int i=1;i<m;i++){
            db[i]=db[i-1]+s2[i];
        }
        return f(0,0,s1,s2,dp);
    }
};