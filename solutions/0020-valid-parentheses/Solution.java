class Solution {
    public boolean isValid(String s) {
        Deque<Character> q = new ArrayDeque<>();
        Set<Character> st = new HashSet<>();
        int n = s.length();
        st.add('(');
        st.add('{');
        st.add('[');
        for(int i=0;i<n;i++){
            char o = s.charAt(i);
            if(!st.contains(o)){
                if(q.isEmpty())return false;
                char e = q.pollLast();
                switch(o){
                    case ')':
                    if(e!='('){
                        return false;}else break;
                    case '}':
                    if(e!='{'){return false;}else break;
                    case ']':
                    if(e!='['){return false;}else break;
                }
            }
            else{
                q.addLast(o);
            }
        }
        return q.isEmpty();
    }
}