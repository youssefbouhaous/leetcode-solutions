class Solution {
    int dp[105][105][105];
    int f(vector<int>&nums,int i,int& k,int op1,int op2){
        if(i==nums.size()) return 0;
        if(dp[i][op1][op2]!=-1) return dp[i][op1][op2];
        int o1=0;
        int o2=0;
        int o12=0;
        int o21=0;
        if(op1>0){
            o1=nums[i]/2+f(nums,i+1,k,op1-1,op2);
        }
        if(op2>0){
            if(nums[i]>=k)
            o2=k+f(nums,i+1,k,op1,op2-1);
        }
        if(op1>0 && op2>0){
            if(nums[i]>=k)
            o12=k+((nums[i]-k)/2)+f(nums,i+1,k,op1-1,op2-1);
        }
        if(op1>0 && op2>0){
            if((nums[i]+1)/2>=k)
            o21=(nums[i]/2)+k+f(nums,i+1,k,op1-1,op2-1);
        }
        return dp[i][op1][op2]=max({f(nums,i+1,k,op1,op2),o1,o2,o12,o21});
    }
public:
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n=nums.size();
        for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) for(int l=0;l<=n;l++) dp[i][j][l]=-1;
        int s=0;
        for(auto x:nums) s+=x;
        return s-f(nums,0,k,op1,op2);
    }
};