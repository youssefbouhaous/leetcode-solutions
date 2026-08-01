class Solution {
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;
        for(int i=0;i<n;i++){
            if(nums[i]<=0 || nums[i]>n){
                nums[i]=n+1;
            }
        }
        for(int i=0;i<n;i++){
            int id = Math.abs(nums[i]);
            if(id!=n+1){
                if(nums[id-1]>0){
                    nums[id-1]=-nums[id-1];
                }
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]>0)return i+1;
        }
        return n+1;
    }
}