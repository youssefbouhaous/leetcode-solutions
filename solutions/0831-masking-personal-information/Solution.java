class Solution {
    public String maskPII(String s) {
        String a = s.toLowerCase();
        if(a.contains("@")){
            String ans[] = a.split("@");
            return ans[0].substring(0,1)+"*****"+ans[0].substring(ans[0].length()-1,ans[0].length())+"@"+ans[1];
        }
        StringBuilder ss = new StringBuilder();
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)>='0' && s.charAt(i)<='9'){
                ss.append(s.charAt(i));
            }
        }
        int n = ss.length();
        String aa = "***-***-"+ss.substring(n-4,n);
        if(n==11)return "+*-"+aa;
        if(n==12)return "+**-"+aa;
        if(n==13)return "+***-"+aa;
        return aa;
    }
}