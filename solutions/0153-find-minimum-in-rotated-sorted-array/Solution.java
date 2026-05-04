class Solution {
    public int findMin(int[] nums) {
        int n = nums.length;
        if(n==1)return nums[0];
        int l = 0;
        int r = n-1;
        int ans = Math.min(nums[0],nums[n-1]);

        while(l<=r){
            int m = (l+r)/2;
            if(m<n-1 && nums[m]<nums[0]){
                ans = Math.min(ans,nums[m]);
                r = m-1;
            }
            else{
                l = m+1;
            }
        }
        return ans;
    }
}