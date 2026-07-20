class Solution {
    public int numPairsDivisibleBy60(int[] time) {
        int[] cnt = new int[60];
        int n = time.length;
        int ans = 0;
        for(int i=0;i<n;i++){
            ans+=cnt[time[i]%60];
            cnt[(60-(time[i])%60)%60]++;
        }
        return ans;
    }
}