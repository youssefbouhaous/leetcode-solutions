class Solution {
    public boolean isMonotonic(int[] nums) {
        int mx = nums[0];
        int n = nums.length;
        for(int i=0;i<nums.length;i++){
            mx=Math.max(mx,nums[i]);
        }
        if(nums[0]==mx){
            for(int i=1;i<n;i++){
                if(nums[i]>nums[i-1])return false;
            }
            return true;
        }else if(nums[n-1]==mx){
            for(int i=1;i<n;i++){
                if(nums[i]<nums[i-1])return false;
            }
            return true;
        }else{
            return false;
        }
    }
}