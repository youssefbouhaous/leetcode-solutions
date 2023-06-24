class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int>c;
        set<int>p;
        vector<int>dp;
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        for(int i=0;i<n;i++){
            c[nums[i]]++;
            p.insert(nums[i]);
        }
        vector<int>a;
        for(auto x:p){
            a.push_back(x);
        }
        if(a.size()==1){
            return a[0]*c[a[0]];
        }
        dp.push_back(a[0]*(c[a[0]]));
        dp.push_back(a[1]*(c[a[1]]));
        if(a[1]!=a[0]+1)
            dp[1]+=dp[0];
        int m=a.size();
        for(int i=2;i<m;i++){
            if(a[i]==a[i-1]+1){
                dp.push_back(a[i]*c[a[i]]+max(dp[i-2],dp[i-1]-a[i-1]*c[a[i-1]]));
            }
            else{
                dp.push_back(a[i]*c[a[i]]+max(dp[i-2],dp[i-1]));
            }
        }
        return max(dp[m-1],dp[m-2]);
    }
};