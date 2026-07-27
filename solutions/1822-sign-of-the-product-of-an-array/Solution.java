class Solution {
    public int arraySign(int[] nums) {
        int p=0;
        int n = nums.length;
        for(int i=0;i<n;i++){
            if(nums[i]==0)return 0;
            p += (nums[i]<0? 1:0);
        }
        return (p%2==0?1:-1);
    }
}