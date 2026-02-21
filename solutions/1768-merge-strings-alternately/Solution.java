class Solution {
    public String mergeAlternately(String a, String b) {
        int n = a.length();
        int m = b.length();
        StringBuilder s = new StringBuilder();
        for(int i=0;i<Math.min(n,m);i++){
            s.append(a.charAt(i));
            s.append(b.charAt(i));
        }
        if(n==m){
            return s.toString();
        }
        if(n<m){
            for(int i=n;i<m;i++){
                s.append(b.charAt(i));
            }
        }
        else{
            for(int i=m;i<n;i++){
                s.append(a.charAt(i));
            }
        }
        return s.toString();
    }
}