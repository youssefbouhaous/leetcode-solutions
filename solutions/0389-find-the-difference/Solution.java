class Solution {
    public char findTheDifference(String s, String t) {
        int[] arr = new int[26];
        int n = s.length();
        for(int i=0;i<n;i++){
            arr[s.charAt(i)-'a']++;
            arr[t.charAt(i)-'a']--;
        }
        arr[t.charAt(n)-'a']--;
        for(int i=0;i<26;i++){
            if(arr[i]<0)return (char)(i+'a');
        }
        return  'a';
    }
}