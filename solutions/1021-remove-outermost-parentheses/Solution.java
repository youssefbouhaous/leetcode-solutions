class Solution {
    public String removeOuterParentheses(String s) {
        int c=0;
        StringBuilder t = new StringBuilder();
        StringBuilder ans = new StringBuilder();
        int n = s.length();
        for(int i=0;i<n;i++){
            char o = s.charAt(i);
            t.append(o);
            if(o=='('){
                c++;
            }else{
                c--;
            }
            if(c==0){
                ans.append(t.substring(1,t.length()-1));
                t.setLength(0);
            }
        }
        return ans.toString();
    }
}