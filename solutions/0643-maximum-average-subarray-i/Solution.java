class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int n=nums.length;
        double ans=0;
        double cur=0;
        for(int i=0;i<k;i++){
            cur+=nums[i];
        }
        cur/=k;
        ans = cur;
        int id=0;
        for(int i=k;i<n;i++){
            cur=(cur*k+nums[i]-nums[id++])/k;
            ans=Math.max(ans,cur);
        }
        return ans;
    }
}