class Solution {
    public String predictPartyVictory(String senate) {
        int d = 0;
        int r = 0;
        int n =senate.length();
        Deque<Character> q = new ArrayDeque<>();
        for(int i=0;i<n;i++){
            if(senate.charAt(i)=='R') r++;
            else d++;
            q.addLast(senate.charAt(i));
        }
        int rr = 0;
        int dd = 0;
        while(true){
            if(q.peekFirst() == 'R' && d ==0) return "Radiant";
            else if(q.peekFirst()=='D' && r== 0)return "Dire";
            else{
                if(q.peekFirst()=='R'){
                    if(rr>0){
                        q.pollFirst();
                        rr--;
                        r--;
                    }
                    else{
                        dd++;
                        q.addLast(q.pollFirst());
                    }
                }else{
                    if(dd>0){
                        q.pollFirst();
                        dd--;
                        d--;
                    }
                    else{
                        rr++;
                        q.addLast(q.pollFirst());
                    }
                }
            }
        }
    }
}