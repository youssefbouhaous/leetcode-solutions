class Solution {
    public int findPeakElement(int[] nums) {
        int n = nums.length;
        if(n==1)return 0;
        if(n==2) return nums[0]>nums[1] ? 0 : 1;
        if(nums[n-1]>nums[n-2])return n-1;
        if(nums[0]>nums[1])return 0;
        int l = 0;
        int r = n - 1;
        while(l<=r){
            int m = (l+r)/2;
            if(m>0 && m<n-1){
                if(nums[m]>nums[m-1] && nums[m]>nums[m+1]){
                    return m;
                }
            }
            if(m>0){
                if(nums[m]>nums[m-1]){
                    l = m+1;
                }
                else{
                    r = m-1;
                }
            }
            else if(m<n-1){
                if(nums[m]>nums[m+1]){
                    r = m-1;
                }
                else{
                    l = m+1;
                }
            }
            else{
                break;
            }
        }
        return 0;
    }
}