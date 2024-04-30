class Solution {
public:
    bool wordBreak(string s, vector<string>& d) {
        vector<bool>dp(s.size());
        for(auto x:d){
            if(s.size()>=x.size()){
                if(s.substr(0,x.size())==x){
                    dp[x.size()-1]=true;
                }
            }
        }
        for(int i=1;i<s.size();i++){
            if(dp[i-1]==true){
                for(auto x:d){
                    if(s.size()-i>=x.size()){
                        if(s.substr(i,x.size())==x){
                            dp[x.size()+i-1]=true;
                        }
                    }
                }
            }
        }
        return dp[s.size()-1];
    }
};