class Solution {
    public boolean rotateString(String s, String g) {
        int n = s.length();
        int m = g.length();
        if(n!=m)return false;
        for(int i=0;i<n;i++){
            int j = i;
            boolean is = true;
            for(int k=0;k<n;k++,j++){
                if(s.charAt(k)!=g.charAt(j%n)){
                    is=false;break;
                }
            }
            if(is)return true;
        }
        return false;
    }
}