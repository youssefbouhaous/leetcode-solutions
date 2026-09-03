class Solution {
    public int findPermutationDifference(String s, String t) {
        int ans=0;
        int n = s.length();
        for(int i=0;i<n;i++)ans+=Math.abs(i-t.indexOf(s.charAt(i)));
        return ans;
    }
}