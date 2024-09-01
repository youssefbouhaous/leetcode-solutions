class Solution {
    int dp[200005];
    int l,h,z,o;
    const int mod=1000000007;
    int f(int c){
        if(dp[c]!=-1) return dp[c];
        if(c>=l && c<=h){
            return dp[c]=(1+f(c+o)+f(c+z))%mod;
        }
        if(c>h) return dp[c]=0;
        return dp[c]=(f(c+z)+f(c+o))%mod;
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        for(int i=0;i<200005;i++) dp[i]=-1;
        l=low;
        h=high;
        z=zero;
        o=one;
        return f(0);
    }
};