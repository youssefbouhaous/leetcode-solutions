class Solution {
    public String decodeString(String s) {
        Deque<Character> q = new ArrayDeque<>();
        int n = s.length();
        StringBuilder ans = new StringBuilder();
        for(int i=0;i<n;i++){
            char o = s.charAt(i);
            if(o!=']')q.addLast(o);
            else{
                StringBuilder tmp = new StringBuilder();
                while(o!='['){
                    tmp.append(o);
                    o=q.pollLast();
                }
                StringBuilder nu = new StringBuilder();
                o=q.pollLast();
                nu.append(o);
                while(!q.isEmpty() && o>='0' && o<='9'){
                    o=q.pollLast();
                    if(o>='0' && o<='9')
                    nu.append(o);
                    else q.addLast(o);
                }
                nu.reverse();
                int nn = Integer.parseInt(nu.toString());
                while(nn-->0){
                    StringBuilder tt = new StringBuilder(tmp);
                    while(tt.length()>0){
                    q.addLast(tt.charAt(tt.length()-1));
                    tt.setLength(tt.length()-1);}
                }
                // System.out.println(nu);
            }
        }
        while(!q.isEmpty()){
            char o = q.pollFirst();
            if(o!=']')
            ans.append(o);
        }
       return ans.toString();
    }
}
