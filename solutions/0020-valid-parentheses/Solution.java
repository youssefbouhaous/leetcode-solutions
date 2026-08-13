class Solution {
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<>();
        int n = s.length();
        Set<Character> op = new HashSet<>(List.of('(','{','['));
        for(int i=0;i<n;i++){
            char o = s.charAt(i);
            if(op.contains(o)){
                st.push(o);
            }else{
                if(st.isEmpty())return false;
                switch(o){
                    case ')':
                    if(st.pop()!='(')return false;
                        break;
                    case ']':
                    if(st.pop()!='[')return false;
                        break;
                    case '}':
                    if(st.pop()!='{')return false;
                        break;
                }
            }
        }
        return st.isEmpty();
    }
}