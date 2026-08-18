class Solution {
    public int beautySum(String s) {
        int n = s.length();
        int ans = 0;
        for(int i=0;i<n;i++){
            int[] cnt = new int[26];
            for(int j=i;j<n;j++){
                int o = s.charAt(j)-'a';
                cnt[o]++;
                int mx = 0;
                int mn = Integer.MAX_VALUE;   
                for(int l=0;l<26;l++){
                    if(cnt[l]!=0){
                    mx=Math.max(mx,cnt[l]);
                    mn=Math.min(mn,cnt[l]);}
                    // System.out.println("mx:"+mx+"mn:"+mn);
                }
                ans += mx-mn;
            }
        }
        return ans;
    }
}