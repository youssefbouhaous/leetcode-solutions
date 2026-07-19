class Solution {
    public String decodeString(String s) {
        Deque<Character> st = new ArrayDeque<>();
        int n = s.length();
        for(int i=0;i<n;i++){
            char o = s.charAt(i);
            if(o!=']'){
                st.addLast(o);
            }else{
                StringBuilder nu = new StringBuilder("");
                StringBuilder tmp = new StringBuilder("");
                while(!st.isEmpty() && st.peekLast()!='[' ){
                    tmp.append(st.pollLast());
                }
                st.pollLast();
                while(!st.isEmpty()){
                    if(st.peekLast()>='0' && st.peekLast()<='9')
                    nu.append(st.pollLast());
                    else break;
                }
                nu.reverse();
                int nn = Integer.parseInt(nu.toString());
                StringBuilder tt = new StringBuilder("");
                tmp.reverse();
                while(nn-->0){
                    tt.append(tmp);
                }
                // System.out.println(tt);
                for(int ii=0;ii<tt.length();ii++)st.addLast(tt.charAt(ii));
            }
        }
        StringBuilder ans = new StringBuilder("");
        while(!st.isEmpty())ans.append(st.pollFirst());
        return ans.toString();
    }
}
