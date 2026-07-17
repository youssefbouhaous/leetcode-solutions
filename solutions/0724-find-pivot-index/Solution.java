class Solution {
    public int pivotIndex(int[] nums) {
        int s = Arrays.stream(nums).sum();
        int cur = 0;
        int n = nums.length;
        int ans = -1;
        if(s-nums[0]==0)return 0;
        for(int i=1;i<n;i++){
            cur+=nums[i-1];
            if(cur == s-cur-nums[i])return i;
        }
        return ans;
    }
}