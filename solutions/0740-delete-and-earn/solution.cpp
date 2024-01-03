class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int>v;
        map<int,int>d;
        for(auto x:nums){
            if(d[x]!=0){
                d[x]++;
            }
            else{
                v.push_back(x);
                d[x]++;
            }
        }
        int n=v.size();
        sort(v.begin(),v.end());
        if(n==1){
            return v[0]*d[v[0]];
        }
        if(n==2){
            if(v[1]==v[0]+1){
            return max(v[0]*d[v[0]],v[1]*d[v[1]]);
            }
            else{
                return v[0]*d[v[0]]+v[1]*d[v[1]];
            }
        }
        int dp[50'000];
        dp[0]=v[0]*d[v[0]];
        if(v[0]+1==v[1]){
            dp[1]=max(v[1]*d[v[1]],dp[0]);
        }
        else{
            dp[1]=v[1]*d[v[1]]+v[0]*d[v[0]];
        }
        for(int i=2;i<n;i++){
            if(v[i]==v[i-1]+1){
                dp[i]=max(dp[i-1],dp[i-2]+v[i]*d[v[i]]);
            }
            else{
                dp[i]=dp[i-1]+v[i]*d[v[i]];
            }
        }
        return max(dp[n-1],dp[n-2]);
    }
};