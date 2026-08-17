class Solution {
    List<String> ans=new ArrayList<>();
    String s;
    int rml = 0;
    int rmr = 0;
    HashSet<String> st = new HashSet<>();
    void f(StringBuilder t,int i,int rml,int rmr,int b){
        if(b==0 && rml==0 && rmr==0 && i==s.length() && !st.contains(t.toString())){
            st.add(t.toString());
        }
        if(i==s.length())return;
        char o = s.charAt(i);
        if(o==')'){
            if(rmr>0){
                f(t,i+1,rml,rmr-1,b);
            }
            if(b>0){
                t.append(o);
                f(t,i+1,rml,rmr,b-1);
                t.deleteCharAt(t.length()-1);
            }
        }else if(o=='('){
            if(rml>0){
                f(t,i+1,rml-1,rmr,b);
                t.append(o);
                f(t,i+1,rml,rmr,b+1);
                t.deleteCharAt(t.length()-1);
            }else{
                t.append(o);
                f(t,i+1,rml,rmr,b+1);
                t.deleteCharAt(t.length()-1);
            }
        }else{
            t.append(o);
            f(t,i+1,rml,rmr,b);
            t.deleteCharAt(t.length()-1);
        }
    }
    public List<String> removeInvalidParentheses(String s) {
        this.s = s;
        int balance = 0;

        for (char ch : s.toCharArray()) {
            if (ch == '(') {
                balance++;
            } else if (ch == ')') {
                if (balance > 0) {
                    balance--;
                } else {
                    rmr++;
                }
            }
        }
        rml = balance;
        StringBuilder t = new StringBuilder();
        f(t,0,rml,rmr,0);
        for(String p:st)ans.add(p);
        return ans;
    }
}