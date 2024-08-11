class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int>count;
        vector<int>v;
        for(auto x:nums){
            if(count[x]==0) v.push_back(x);
            count[x]++;
        }
        sort(v.begin(),v.end());
        int n=v.size();
        if(n==1) return count[v[0]]*v[0];
        vector<int>dp(n);
        dp[0]=v[0]*count[v[0]];
        if(v[1]!=v[0]+1){
            dp[1]=dp[0]+v[1]*count[v[1]];
        }
        else{
            dp[1]=max(dp[0],v[1]*count[v[1]]);
        }
        for(int i=2;i<n;i++){
            if(v[i]!=v[i-1]+1){
                dp[i]=max(dp[i-1],dp[i-2])+v[i]*count[v[i]];
            }
            else{
                dp[i]=max(dp[i-1],count[v[i]]*v[i]+dp[i-2]);
            }
        }
        return max(dp[n-1],dp[n-2]);
    }
};