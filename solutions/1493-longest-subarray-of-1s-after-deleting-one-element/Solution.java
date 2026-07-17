class Solution {
    public int longestSubarray(int[] nums) {
        int c=1;
        int l = 0;
        int r = 0;
        int ans = 0;
        while(r<nums.length){
            if(nums[r]==0)c--;
            if(c<0){
                if(nums[l]==0)c++;
                l++;
            }
            r++;
            ans = Math.max(ans,r-l-1);
        }
        return ans;
    }
}