class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        //cout<<"::::::::::::::"<<endl;
        int n=nums.size();
        vector<int>dp(n,0);
        for(int i=n-1;i>-1;i--){
            if(i==n-1 || dp[i]!=0){
            for(int j=i-1;j>-1;j--){
                if(abs(nums[i]-nums[j])<=target){
                    dp[j]=max(dp[j],dp[i]+1);
                }
            }
            }
            /*cout<<i<<"::"<<endl;
            for(auto x:dp){
                cout<<x<<" ";
            }
            cout<<endl;*/
        }
        if(dp[0]==0){
            return -1;
        }
        return dp[0];
    }
};