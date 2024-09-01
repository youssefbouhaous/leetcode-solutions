class Solution {
    int dp[105];
    int f(int i,string&s){
        if(dp[i]!=-1) return dp[i];
        if(i>=s.size()) return dp[i]=1;
        if(s[i]=='0') return dp[i]=0;
        if(i==s.size()-1) return dp[i]=1;
        if(s[i]=='1')
            return dp[i]=f(i+1,s)+f(i+2,s);
        if(s[i]=='2' && s[i+1]<'7')
            return dp[i]=f(i+1,s)+f(i+2,s);
        return dp[i]=f(i+1,s);
    }
public:
    int numDecodings(string s) {
        if(s[0]=='0') return 0;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1] && s[i]=='0') return 0;
        }
        for(int i=0;i<105;i++)dp[i]=-1;
        return f(0,s);
    }
};