class Solution {
    public String mergeAlternately(String a, String b) {
        int n = a.length();
        int m = b.length();
        int i=0;
        int j=0;
        StringBuilder ans = new StringBuilder();
        while(i<n || j<m){
            if(i<n)ans.append(a.charAt(i++));
            if(j<m)ans.append(b.charAt(j++));
        }
        return ans.toString();
    }
}