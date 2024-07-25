class Solution {
    int dp[503][503][26];
    int find(int pos,int prev,int cnt,vector<int>&nums){
        if(pos==nums.size()){
            return 0;
        }
        int ans=-1;
        if(dp[pos][prev+1][cnt]!=-1){
            return dp[pos][prev+1][cnt];
        }
        if(prev==-1){
            ans=max(ans,find(pos+1,-1,cnt,nums));
            ans=max(ans,1+find(pos+1,pos,cnt,nums));
        }
        else{
            if(nums[pos]==nums[prev]){
                ans=max(ans,1+find(pos+1,pos,cnt,nums));
            }
            else{
                ans=max(ans,find(pos+1,prev,cnt,nums));
                if(cnt>0){
                    ans=max(ans,1+find(pos+1,pos,cnt-1,nums));
                }
            }
        }
        return dp[pos][prev+1][cnt]=ans;
    }
public:
    int maximumLength(vector<int>& nums, int k) {
        memset(dp, -1, sizeof(dp));
        return find(0,-1,k,nums);
    }
};