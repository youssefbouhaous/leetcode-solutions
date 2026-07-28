class Solution {
    public boolean isMonotonic(int[] nums) {
        int n = nums.length;
        if(n==1)return true;
        int s = 0;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1])continue;
            int cs = (nums[i-1]-nums[i])/Math.abs(nums[i-1]-nums[i]);
            if(s==0)s=cs;
            if(cs != s)return false;
        } 
        return true;
    }
}