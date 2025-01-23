class Solution {
public:
    string s,p;
    int dp[25][25];
    bool f(int i,int j){
        
        if(i>=s.size() && j>=p.size())return true;
        if(j>=p.size())return false;
        if(i<25 && j<25 && dp[i][j]!=-1)return dp[i][j];
        if(i>=s.size()){
            if(j==p.size()-1 && p[j]=='*')return dp[i][j]=true;
            return j<p.size()-1 && p[j+1]=='*' && f(i+1,j+2);
        }
        if(j<p.size()-1 && p[j+1]=='*'){
            bool ans=false;
            if(p[j]==s[i] || p[j]=='.'){
                ans|=f(i+1,j);
                ans|=f(i+1,j+2);
            }
            return dp[i][j]=f(i,j+2) || ans;
        }
        else if(p[j]=='.' || s[i]==p[j]){
            return dp[i][j]=f(i+1,j+1);
        }
        else return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        this->s=s;
        this->p=p;
        for(int i=0;i<25;i++)for(int j=0;j<25;j++)dp[i][j]=-1;
        return f(0,0);
    }
};