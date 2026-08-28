class Solution {
    public int countDigitOccurrences(int[] nums, int d) {
        int ans = 0;
        int n = nums.length;
        for(int i=0;i<n;i++){
            int x = nums[i];
            while(x>0){
                ans += (x%10==d?1:0);
                x/=10;
            }
        }
        return ans;
    }
}