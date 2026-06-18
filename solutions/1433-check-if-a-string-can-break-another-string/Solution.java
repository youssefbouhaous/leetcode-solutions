class Solution {
    public boolean checkIfCanBreak(String s1, String s2) {
        char[] a = s1.toCharArray();
        char[] b = s2.toCharArray();
        int n = s1.length();
        Arrays.sort(a);
        Arrays.sort(b);
        boolean f1 = true;
        boolean f2 = true;
        for(int i=0;i<n;i++){
            f1&=a[i]>=b[i];
            f2&=a[i]<=b[i];
        }
        return f1||f2;
    }
}