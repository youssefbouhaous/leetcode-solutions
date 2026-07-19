class Solution {
    public int[] sortedSquares(int[] nums) {
        int l = 0;
        int n = nums.length;
        int r = n-1;
        int[] ans = new int[n];
        for(int i=n-1;i>=0;i--){
            if(Math.abs(nums[r])>Math.abs(nums[l])){
                ans[i] = nums[r]*nums[r];
                r--;
            }else{
                ans[i] = nums[l]*nums[l];
                l++;
            }
        }
        return ans;
    }
}