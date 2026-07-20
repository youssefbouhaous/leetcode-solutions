class Solution {
    public int countNicePairs(int[] nums) {
        int mod = 1000000007;
        Map<Long,Long> mp = new HashMap<>();
        int n = nums.length;
        for(int i=0;i<n;i++){
            StringBuilder tmp = new StringBuilder(""+nums[i]);
            tmp.reverse();
            long tint = Integer.parseInt(tmp.toString());
            long o = -tint+nums[i];
            mp.put(o,mp.getOrDefault(o,0L)+1);
        }
        long ans = 0;
        for(long x:mp.keySet()){
            long nn = mp.get(x);
            // System.out.println(x+ " cnt: "+mp.get(x));
            ans = (ans+nn*(nn-1)/2)%mod;
        }
        return (int)ans;
    }
}