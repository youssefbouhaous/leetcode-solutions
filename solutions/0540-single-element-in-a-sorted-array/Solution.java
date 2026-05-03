class Solution {
    public int singleNonDuplicate(int[] nums) {
        int n = nums.length;
        int l = 0;
        int r = n - 1;
        int m = 0;
        while(l<=r){
            m = (l+r)/2;
            int i = m;
            if(m>0 && nums[i]==nums[i-1]){
                if(i%2==0){
                    r = m-1;
                }
                else{
                    l = m+1;
                }
                continue;
            }
            if(m<n-1 && nums[i]==nums[i+1]){
                if((i+1)%2 == 0){
                    r = m - 1;
                }
                else{
                    l = m + 1;
                }
                continue;
            }
            return nums[i];
        }
        return nums[m];
    }
}