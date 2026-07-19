class Solution {
    public int firstUniqChar(String s) {
        int[] a = new int[26];
        int n = s.length();
        for(int i=0;i<n;i++){
            a[s.charAt(i)-'a']++;
        }
        for(int i=0;i<n;i++){
            if(a[s.charAt(i)-'a']==1)return i;
        }
        return -1;
    }
}