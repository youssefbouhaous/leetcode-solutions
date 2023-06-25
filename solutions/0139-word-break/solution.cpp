class Solution {
public:
    bool wordBreak(string s, vector<string>& word) {
        set<string>st;
        for(auto x:word){
            st.insert(x);
        }
        int n=s.size();
        vector<bool>dp(n+1,0);
        dp[n]=1;
        for(int i=n-1;i>-1;i--){
            string tmp;
            for(int j=i;j<n;j++){
                tmp.push_back(s[j]);
                
                if(st.find(tmp)!=st.end()){
                    if(dp[i]==0)
                    dp[i]=dp[j+1];
                }
                cout<<tmp<<" i "<<i<<" j "<<j<<" dp : "<<dp[i]<<endl;
            }
        }
        return dp[0];
    }
};