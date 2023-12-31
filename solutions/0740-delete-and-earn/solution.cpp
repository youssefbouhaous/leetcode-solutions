class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        map<int,int>d;
        set<int>st;
        for(auto x:nums){
            d[x]++;
            st.insert(x);
        }
        nums.clear();
        for(auto x:st){
            nums.push_back(x);
        }
        int n=nums.size();
        if(n==1){
            return d[nums[0]]*nums[0];
        }
        vector<int>dp(n);
        dp[0]=nums[0]*d[nums[0]];
        for(int i=1;i<n;i++){
            cout<<nums[i]<<" ";
            if(nums[i]!=nums[i-1]+1){
                dp[i]=dp[i-1]+d[nums[i]]*nums[i];
            }
            else{
                dp[i]=max(dp[i-1]-d[nums[i-1]]*nums[i-1]+d[nums[i]]*nums[i],dp[i-1]);
            }
            if(i>1){
                dp[i]=max(dp[i],dp[i-2]+d[nums[i]]*nums[i]);
            }
        }
        return max(dp[n-1],dp[n-2]);
    }
};