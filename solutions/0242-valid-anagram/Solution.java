class Solution {
    public boolean isAnagram(String s, String t) {
        int n = s.length();
        int m = t.length();
        if(n!=m)return false;
        int[] cnt = new int[26];
        for(int i=0;i<n;i++){
            cnt[s.charAt(i)-'a']++;
            cnt[t.charAt(i)-'a']--;
        }
        for(int i=0;i<26;i++){
            if(cnt[i]<0)return false;
        }
        return true;
    }
}