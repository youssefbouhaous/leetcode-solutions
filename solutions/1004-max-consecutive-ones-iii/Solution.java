class Solution {
    public int longestOnes(int[] nums, int k) {
        int c=k;
        int l=0;
        int r=0;
        int n=nums.length;
        int ans=0;
        while(r<n &&l<n){
            if(nums[r]==1)r++;
            else{
                c--;
                while(c<0){
                    if(nums[l]==0){
                        c++;
                    }
                    l++;
                }
                r++;
            }
            ans = Math.max(ans,r-l);
        }
        return ans;
    }
}