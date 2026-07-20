class Solution {
    public int search(int[] nums, int t) {
        int n = nums.length;
        int l = 0;
        int r = n-1;
        while(l<=r){
            int m = (l+r)/2;
            if(nums[m]==t)return m;
            else if(nums[m]>t)r--;
            else l++;
        }
        return -1;
    }
}