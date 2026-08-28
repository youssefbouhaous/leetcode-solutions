class Solution {
    public int numSplits(String s) {
        int[] pre = new int[26];
        int[] suf = new int[26];
        int n = s.length();
        for(int i=0;i<n;i++){
            int o = s.charAt(i)-'a';
            suf[o]++;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            int o = s.charAt(i)-'a';
            pre[o]++;
            suf[o]--;
            int c1=0;
            int c2=0;
            for(int j=0;j<26;j++){
                if(pre[j]>0)c1++;
                if(suf[j]>0)c2++;
            }
            if(c1==c2)ans++;
        }
        return ans;
    }
}