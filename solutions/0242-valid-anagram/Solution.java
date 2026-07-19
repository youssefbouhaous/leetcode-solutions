class Solution {
    public boolean isAnagram(String s, String t) {
        int n = s.length();
        int m = t.length();
        if(n!=m)return false;
        int[] a=new int[26];
        int[] b=new int[26];
        for(int i=0;i<n;i++){
            a[s.charAt(i)-'a']++;
            b[t.charAt(i)-'a']++;
        }
        for(int i=0;i<26;i++)if(a[i]!=b[i])return false;
        return true;
    }
}