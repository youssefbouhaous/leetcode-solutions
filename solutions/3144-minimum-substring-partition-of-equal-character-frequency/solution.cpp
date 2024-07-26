class Solution {
public:
    bool is_balanced(vector<int>&charFreq){
        int c=-1;
        for(auto x:charFreq){
            if(x!=0){
                if(c==-1)
                    c=x;
                else if(c!=x)
                    return false;
            }
        }
        return true;
    }
    int minimumSubstringsInPartition(string s) {
        int n=s.size();
        vector<int>dp(n,n);
        for(int i=0;i<n;i++){
            vector<int>charFreq(26,0);
            for(int j=i;j>-1;j--){
                charFreq[s[j]-'a']++;
                if(is_balanced(charFreq))
                dp[i]= (j==0) ? 1:min(dp[i],1+dp[j-1]);
            }
        }
        return dp[n-1];
    }
};