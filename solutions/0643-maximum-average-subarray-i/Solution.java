class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int n = nums.length;
        int l = 0;
        int r = k-1;
        double ans = 0;
        double cur = 0;
        for(int i =0;i<k;i++){
            ans += nums[i];
        }
        ans /= k;
        cur = ans;
        for(int i=0;i<n-k;i++){
            cur = (cur*k-nums[i]+nums[k+i])/k;
            ans =Math.max(  cur   , ans   ); 
            //System.out.println(ans+ " i"+i);
        }
        return ans;
    }
}