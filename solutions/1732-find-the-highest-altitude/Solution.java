class Solution {
    public int largestAltitude(int[] gain) {
        int p=0;
        int mx=0;
        int n=gain.length;
        for(int i=0;i<n;i++){
            p+=gain[i];
            mx=Math.max(mx,p);
        }
        return mx;
    }
}