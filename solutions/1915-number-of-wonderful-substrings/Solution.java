class Solution {
    public long wonderfulSubstrings(String word) {
        Map<Integer,Long> mp = new HashMap<>();
        mp.put(0,1L);
        int mask = 0;
        long ans = 0;
        int n = word.length();
        for(int i=0;i<n;i++){
            int o = word.charAt(i)-'a';
            mask ^= (1<<(o));
            ans += mp.getOrDefault(mask, 0L);
            for (int k = 0; k < 10; k++) {
                int prev = mask ^ (1 << k);
                ans += mp.getOrDefault(prev, 0L);
            }
            mp.put(mask,mp.getOrDefault(mask,0L)+1L);
        }
        return ans;
    }
}