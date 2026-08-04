class Solution {
    public int calculate(String s) {
        int ans = 0;
        int i = 0;
        int n = s.length();
        Deque<String> q = new ArrayDeque<>();
        Set<Character> opDM = new HashSet<>(List.of('/','*'));
        while(i<n){
            char o = s.charAt(i);
            if(o==' ')i++;
            else if(Character.isDigit(o)){
                int nt = 0;
                while (i<n && Character.isDigit(o)){
                    nt = nt*10+o-'0';
                    i++;
                    if(i<n)
                        o=s.charAt(i);
                }
                q.addLast(nt+"");
            }
            else{
                i++;
                q.addLast(o+"");
            }
        }
        Deque<String> fq = new ArrayDeque<>();
        while (q.size()>1){
            String a=q.pollFirst();
            String b=q.pollFirst();
            if(!Character.isDigit(a.charAt(0)) && a.length()==1){
                if(Character.isDigit(b.charAt(0))){
                    q.addFirst("-"+b);
                }
                else q.addFirst(-Integer.parseInt(b)+"");
                continue;
            }
            String c = q.pollFirst();
            if(!opDM.contains(b.charAt(0))){
                fq.addLast(a);
                fq.addLast(b);
                q.addFirst(c);
            }
            else{
                if(b.charAt(0)=='*'){
                    q.addFirst(Integer.parseInt(a)*Integer.parseInt(c)+"");
                }else{
                    q.addFirst(Integer.parseInt(a)/Integer.parseInt(c)+"");
                }
            }
        }
        fq.addLast(q.peekLast());
        while (fq.size()>1){
            String a=fq.pollFirst();
            String b=fq.pollFirst();
            if(!Character.isDigit(a.charAt(0)) && a.length()==1){
                if(Character.isDigit(b.charAt(0))){
                    fq.addFirst("-"+b);
                }
                else fq.addFirst(-Integer.parseInt(b)+"");
                continue;
            }
            String c = fq.pollFirst();

                if(b.charAt(0)=='+'){
                    fq.addFirst(Integer.parseInt(a)+Integer.parseInt(c)+"");
                }else{
                    fq.addFirst(Integer.parseInt(a)-Integer.parseInt(c)+"");
                }

        }
        return Integer.parseInt(fq.peekLast());
    }
}