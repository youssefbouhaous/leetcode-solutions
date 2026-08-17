class Solution {
    public String minRemoveToMakeValid(String s) {
        StringBuilder t= new StringBuilder();
        int c = 0;
        int n = s.length();
        for(int i=0;i<n;i++){
            char o = s.charAt(i);
            if(o=='('){
                c++;
            }
            else if(o==')'){
                c--;
            }
            if(c<0){
                c++;
            }else{
                t.append(o);
            }
        }
        if(c==0)return t.toString();
        StringBuilder tt= new StringBuilder();
        n = t.length();
        t.reverse();
        for(int i=0;i<n;i++){
            char o = t.charAt(i);
            if(o=='(' && c>0){
                c--;
            }else{
                tt.append(o);
            }
        }
        return tt.reverse().toString();
    }
}