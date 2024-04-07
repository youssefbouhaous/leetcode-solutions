class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans=1;
        int c=1;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                c++;
                ans=max(ans,c);
            }
            else{
                c=1;
            }
        }
        c=1;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                c++;
                ans=max(ans,c);
            }
            else{
                c=1;
            }
        }
        return ans;
    }
};