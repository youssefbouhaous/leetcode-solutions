class Solution {
    public int maxSubArray(int[] nums) {
        int ans = nums[0];
        int cur = ans;
        int n = nums.length;
        for(int i=1;i<n;i++){
            if(nums[i]>cur+nums[i]){
                cur=nums[i];
            }else cur+=nums[i];
            ans=Math.max(ans,cur);
        }
        return ans;
    }
}