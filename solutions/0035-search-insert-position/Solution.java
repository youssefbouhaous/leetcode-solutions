class Solution {
    public int searchInsert(int[] nums, int t) {
        int n=nums.length;
        int l=0;
        int r=n-1;
        int m=0;
        while(l<=r){
            m=(l+r)/2;
            if(nums[m]==t)return m;
            else if(nums[m]>t)r--;
            else l++;
        }
        if(m==n-1 && t>nums[n-1])return n;
        return m;
    }
}