class Solution {
    public int largestAltitude(int[] gain) {
        int cur = 0;
        int ans = 0;
        for(int i =0;i<gain.length;i++){
            cur+=gain[i];
            ans=Math.max(ans,cur);
        }
        return ans;
    }
}