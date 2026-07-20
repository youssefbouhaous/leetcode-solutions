class Solution {
    public boolean isValid(String s) {
        Deque<Character> q = new ArrayDeque<>();
        int n = s.length();
        for(int i=0;i<n;i++){
            char o = s.charAt(i);
            switch(o){
                case ')':
                 if(!q.isEmpty() && q.peekLast()=='('){
                    q.pollLast();break;}
                 else return false;
                case '}':
                 if(!q.isEmpty() && q.peekLast()=='{'){
                    q.pollLast();break;}
                 else return false;
                case ']':
                 if(!q.isEmpty() && q.peekLast()=='['){
                    q.pollLast();break;}
                 else return false;
                default:
                    q.addLast(o);
            }
        }
        return q.isEmpty();
    }
}