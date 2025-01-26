class Solution {
    private:
    string s,p;
    int dp[2005][2005];
    bool f(int i,int j){   
        if(dp[i][j]!=-1)return dp[i][j];
        if(j>=p.size() && i>=s.size())return dp[i][j]=true;
        if(j>=p.size())return dp[i][j]=false;
        if(i>=s.size()){
            if(j==p.size()-1 && (p[j]=='*'))return dp[i][j]=true;
            return dp[i][j]=(p[j]=='*' && f(i,j+1));
        }
        bool ans=false;
        if(p[j]!='?' && p[j]!='*' && p[j]!=s[i])return dp[i][j]=false;
        if(p[j]=='*'){
            return dp[i][j]=(f(i+1,j) || f(i+1,j+1) || f(i,j+1));
        }
        if(p[j]=='?' || p[j]==s[i]){
            return dp[i][j]=f(i+1,j+1);
        }
        return dp[i][j]=false;
    }
public:
    bool isMatch(string s, string p) {
        this->s=s;
        this->p=p;
        if(p=="" && s!="")return false;
        if(p==s)return true;
        string pp;
        for(int i=0;i<p.size()-1;i++){
            if(p[i]=='*' && p[i+1]=='*'){
                continue;
            }
            else{
                pp.push_back(p[i]);
            }
        }
        pp.push_back(p.back());
        this->p=pp;
        //cout<<pp;
        for(int i=0;i<s.size()+5;i++)for(int j=0;j<s.size()+5;j++)dp[i][j]=-1;
        return f(0,0);
    }
};