class Solution {
    public String licenseKeyFormatting(String s, int k) {
        StringBuilder ans = new StringBuilder();
        StringBuilder tmp = new StringBuilder();
        int n = s.length();
        for(int i=0;i<n;i++){
            char c = s.charAt(i);
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c>='0' && c<='9')) {
                tmp.append(Character.toUpperCase(c));
            }
        }
        int m = tmp.length();
        int f = m%k;
        for(int i=0;i<f;i++){
            ans.append(tmp.charAt(i));
        }
        int r = 0;
        for(int i=f;i<m;i++){
            if(r==0)ans.append('-');
            r++;
            ans.append(tmp.charAt(i));
            r = r%k;
        }
        if(!ans.isEmpty() && ans.charAt(0)=='-')ans.deleteCharAt(0);
        return ans.toString();
    }
}