class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int m=*max_element(nums.begin(),nums.end());
        int t=0;
        int ans=0;
        for(auto x:nums){
            if(x==m){
                t++;
            }
            else{
                t=0;
            }
            ans=max(ans,t);
        }
        return ans;
    }
};