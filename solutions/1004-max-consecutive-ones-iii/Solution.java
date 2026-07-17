class Solution {
    public int longestOnes(int[] nums, int k) {
        int l = 0;
        int r = 0;
        int n = nums.length;
        int cur = 0;
        int ans = 0;
        int c = k;
        while(r<n){
            if(nums[r]==0)c--;
            if(c<0){
                if(nums[l]==0)c++;l++;
            }
            r++;
            ans = Math.max(ans,r-l);
        }
        return ans;
    }
}