class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int n= nums.length;
        int mx=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]!=0 && nums[i-1]!=0){
                nums[i] += nums[i-1];
            }
            mx = Math.max(mx,nums[i]);
        }
        return mx;
    }
}