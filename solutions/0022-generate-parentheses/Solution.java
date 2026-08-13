class Solution {
    StringBuilder s = new StringBuilder();
    List<String> ans = new ArrayList<>();
    int n;
    boolean isValid(StringBuilder s){
        int c=0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='(')c++;
            else c--;
            if(c<0)return false;
        }
        return c==0;
    }
    void generate(){
        if(s.length()>2*n)return;
        if(s.length()==2*n){
            if(isValid(s))ans.add(s.toString());
            else return;
        }
        s.append('(');
        generate();
        s.setLength(s.length()-1);
        s.append(')');
        generate();
        s.setLength(s.length()-1);
    }
    public List<String> generateParenthesis(int n) {
        this.n= n;
        generate();
        return ans;
    }
}