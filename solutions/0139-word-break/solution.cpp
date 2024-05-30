class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<bool>dp(s.size());
        for(auto x:wordDict){
            if(s.substr(0,x.size())==x){
                dp[x.size()-1]=true;
            }
        }
        for(int i=0;i<n-1;i++){
            if(dp[i]){
                for(auto x:wordDict){
                    if(s.substr(i+1,x.size())==x){
                        dp[x.size()+i]=true;
                    }
                }
            }
        }
        
        return dp[n-1];
    }
};