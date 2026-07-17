class Solution {
    public int longestOnes(int[] nums, int k) {
        int l = 0;
        int r = 0;
        int n = nums.length;
        int cur = 0;
        int ans = 0;
        int c = k;
        while(r<n){
            ans = Math.max(ans,cur);
            if(nums[r] == 1){
                cur++;r++;
            }else{
                if(c>0){
                    c--;cur++;r++;
                }
                else{
                    if(k==0){
                        cur=0;r++;
                        l=r;
                    }else{
                        l=r;
                        cur=0;
                        c=k;
                        while(l>0&&c>0){
                            l--;
                            cur++;
                            if(nums[l]==0)c--;
                        }
                        r++;
                    }
                }
            }
            ans = Math.max(ans,cur);
        }
        return ans;
    }
}