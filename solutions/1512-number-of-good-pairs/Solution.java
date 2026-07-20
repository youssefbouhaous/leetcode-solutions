class Solution {
    public int numIdenticalPairs(int[] nums) {
        int ans=0;
        int n = nums.length;
        int[] suf = new int[101];
        for(int i=n-1;i>=0;i--){
            ans+=suf[nums[i]];
            suf[nums[i]]++;
        }
        return ans;
    }
}