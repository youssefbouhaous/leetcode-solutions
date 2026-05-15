class Solution {
    public boolean isTrionic(int[] nums) {
        int a = 0;
        int b = 0;
        int n = nums.length;
        if(n<=3)return false;
        if(nums[0]>=nums[1])return false;
        boolean found = false;
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1])return false;
            if(nums[i]>nums[i+1]){
                a = i;
                found = true;
                break;
            }
        }
        if(!found)return false;
        for(int i=a+1;i<n-1;i++){
            if(nums[i]==nums[i+1])return false;
            if(nums[i]<nums[i+1]){
                b = i;
                found = true;
                break;
            }
        }
        if(!found)return false;
        for(int i=b;i<n-1;i++){
            if(nums[i]>=nums[i+1])return false;
        }
        return a!=b;
    }
}