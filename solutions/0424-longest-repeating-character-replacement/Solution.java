class Solution {
    public int characterReplacement(String s, int k) {
        int[] cnt = new int[26];
        int l=0;
        int r=0;
        int n=s.length();
        int ans=0;
        while(r<n){
            cnt[s.charAt(r)-'A']++;
            int mx=-1;
            int mxc = 0;
            for(int i=0;i<26;i++){
                if(cnt[i]>mx){
                    mxc=i;mx=cnt[i];
                }
            }
            if(r-l+1-mx<=k){
                ans=Math.max(ans,r-l+1);
            }else{
                cnt[s.charAt(l)-'A']--;l++;
                mx=0;mxc=0;
                for(int i=0;i<26;i++){
                    if(cnt[i]>mx){
                        mxc=i;mx=cnt[i];
                    }
                }
                if(r-l+1-mx<=k){
                    ans=Math.max(ans,r-l+1);
                }
            }
            r++;
        }
        return ans;
    }
}