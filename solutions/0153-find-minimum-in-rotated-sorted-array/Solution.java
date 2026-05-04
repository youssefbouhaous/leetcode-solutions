class Solution {
    public int findMin(int[] nums) {
        int n = nums.length;
        if(n==1)return nums[0];
        if(n<4)return Arrays.stream(nums).min().getAsInt();
        if(nums[n-1]>nums[0])return nums[0];
        int m = 0;
        int l = 0;
        int r = n-1;
        while(l<r){
            m = (l+r)/2;
            if(nums[m]<=nums[l] && nums[m]<=nums[r]){
                if(nums[m]<nums[m-1]&&nums[m]<nums[m+1])return nums[m];
                r = m;
            }
            else if(nums[m]>=nums[l] && nums[m]<=nums[r]){
                r = m;
            }
            else{
                l = m+1;
            }
        }
        m = (l+r)/2;
        return nums[m];
    }
}