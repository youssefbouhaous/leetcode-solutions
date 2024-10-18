class Solution {
    int m=0;
    int dp[17][1000001];
    int f(int o,int i,vector<int>&nums){
        //cout<<'o'<<o<<" i "<<i<<endl;
        if(nums.size()<=i) return 0;
        if(dp[i][o]!=-1)return dp[i][o];
        if((o|nums[i])==m) return dp[i][o]=1+f(o,i+1,nums)+f((o|nums[i]),i+1,nums);
        return dp[i][o]=f(o,i+1,nums)+f((o|nums[i]),i+1,nums);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        for(auto& x:nums){
            m|=x;
        }
        for(int i=0;i<17;i++){
            for(int j=0;j<1000001;j++) dp[i][j]=-1;
        }
        return f(0,0,nums);
    }
};