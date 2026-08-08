class Solution {
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;
        for(int i=0;i<n;i++){
            if(nums[i]<=0 || nums[i]>n)nums[i]=n+1;
        }
        for(int i=0;i<n;i++){
            int e = Math.abs(nums[i]);
            if(e!=n+1){
                if(nums[e-1]>0)
                nums[e-1]=-nums[e-1];
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]>0)return i+1;
        }
        return n+1;
    }
}