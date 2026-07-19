class Solution {
    public void reverseString(char[] s) {
        int l=0;
        int n = s.length;
        int r=n-1;
        while(l<r){
            char t = s[l];
            s[l] = s[r];
            s[r] = t;
            l++;r--;
        }
    }
}