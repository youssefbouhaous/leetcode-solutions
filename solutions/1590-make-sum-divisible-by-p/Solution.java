class Solution {
    public int minSubarray(int[] nums, int p) {
        int n = nums.length;
        int[] pre = new int[n+1];
        Map<Integer,Integer> mp = new HashMap<>();
        for(int i=0;i<n;i++){
            pre[i+1]=(pre[i]+nums[i])%p;
        }
        mp.put(0,0);
        int cur = 0;
        int best = n;
        int t = pre[n];
        if(t==0)return 0;
        for(int i=0;i<n;i++){
            int needed = (pre[i+1]-t+p)%p;
            if(needed==0){
                best=Math.min(best,i+1);
            }
            if(mp.get(needed)!=null){
                best=Math.min(best,i-mp.get(needed)+1);
            }
            mp.put(pre[i+1],i+1);
        }
        return best==n?-1:best;
    }
}