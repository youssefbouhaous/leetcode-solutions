class Solution {
    public String decodeString(String s) {
        Stack<Character> st = new Stack<>();
        Stack<Integer> si = new Stack<>();
        int n = s.length();
        int i =0;
        while(i<n){
            char o = s.charAt(i);
            if(o!=']'){
                if(o>'0' && o<='9'){
                    int r = 0;
                    while(i<n && s.charAt(i)>='0' && s.charAt(i)<='9'){
                        o=s.charAt(i++);
                        r = r*10+o-'0';
                    }
                    si.push(r);
                }else{
                    st.push(o);
                    i++;
                }
            }else{
                StringBuilder tmp = new StringBuilder();
                while(o!='['){
                    o=st.pop();
                    if(o!='[')
                    tmp.append(o);
                }
                int r = si.pop();
                tmp.reverse();
                for(int j=0;j<r;j++){
                    for(int l=0;l<tmp.length();l++){
                        st.push(tmp.charAt(l));
                    }
                }
                i++;
            }
        }
        StringBuilder ans = new StringBuilder();
        while(!st.isEmpty()){
            ans.append(st.pop());
        }
        ans.reverse();
        return ans.toString();
    }
}
