class Solution {
    public int maxFreq(String s, int maxLetters, int minSize, int maxSize) {
        int n = s.length();
        long m = 1_000_000_009;
        long p = 31;
        Map<Long,Integer> mp  = new HashMap<>();
        int mx = 0;
        for(int i=0;i<n;i++){
            long tmph = 0;
            long pow = 1;
            int[] cnt = new int[27];
            int uni = 0;
            for(int j=i;j<Math.min(i+minSize,n);j++){
                int o = s.charAt(j)-'a'+1;
                tmph = (tmph + o*pow)%m;
                pow =(p*pow)%m;
                cnt[o]++;
                if(cnt[o]==1)uni++;
            }
            if(uni<=maxLetters && i<=n-minSize){
                mp.put(tmph,mp.getOrDefault(tmph,0)+1);
                mx=Math.max(mx,mp.get(tmph));
            }
        }
        return mx;
    }
}