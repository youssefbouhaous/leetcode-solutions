class Solution {
    public int calculate(String s) {
        /*
        1+2-  6+7 -> [1,+,2,-,6,+,7]
        we don t have () x 1,2,+ => 3 -> [4]
        (4+3-6+3) -> []
        [9,-,9,-,-6]->-6
        (6+3)-9 -(3-9)
        */
        Deque<String> q = new ArrayDeque<>();
        int i = 0;
        int n = s.length();
        while(i<n){
            char o = s.charAt(i);
            if(o==' '){i++;}
            else if(o!=')'){
                if(o>='0' && o<='9'){
                    StringBuilder tmpNumber = new StringBuilder();
                    while(i<n && o>='0' && o<='9'){
                        tmpNumber.append(o);
                        i++;
                        if(i<n){
                            o=s.charAt(i);
                        }
                    }
                    q.addLast(tmpNumber.toString());
                }else{
                    i++;
                    q.addLast(o+"");
                }
            }
            else{
                Deque<String> tmpQ = new ArrayDeque<>();
                while(!q.peekLast().equals("(")){
                    tmpQ.addFirst(q.pollLast());
                }
                q.pollLast();
                while(tmpQ.size()>1){
                    String a = tmpQ.pollFirst();
                    String b = tmpQ.pollFirst();
                    if(a.equals("-")){
                        if(b.charAt(0)!='-'){
                        tmpQ.addFirst(Integer.parseInt("-"+b)+"");continue;
                        }else{ 
                        tmpQ.addFirst(-Integer.parseInt(b)+"");continue;
                        }
                    }
                    String c = tmpQ.pollFirst();
                    if(b.equals("-")){
                        int na = Integer.parseInt(a);
                        int nc = Integer.parseInt(c);
                        tmpQ.addFirst(na-nc+"");
                    }else{
                        int na = Integer.parseInt(a);
                        int nc = Integer.parseInt(c);
                        tmpQ.addFirst(na+nc+"");
                    }
                }
                q.addLast(tmpQ.peekLast());
                i++;
            }
        }
        Deque<String> tmpQ = new ArrayDeque<>();
                while(!q.isEmpty()){
                    tmpQ.addFirst(q.pollLast());
                }
                while(tmpQ.size()>1){
                    String a = tmpQ.pollFirst();
                    String b = tmpQ.pollFirst();
                    if(a.equals("-")){
                        if(b.charAt(0)!='-'){
                        tmpQ.addFirst(Integer.parseInt("-"+b)+"");continue;
                        }else{ 
                        tmpQ.addFirst(-Integer.parseInt(b)+"");continue;
                        }
                    }
                    String c = tmpQ.pollFirst();
                    if(b.equals("-")){
                        int na = Integer.parseInt(a);
                        int nc = Integer.parseInt(c);
                        tmpQ.addFirst(na-nc+"");
                    }else{
                        int na = Integer.parseInt(a);
                        int nc = Integer.parseInt(c);
                        tmpQ.addFirst(na+nc+"");
                    }
                }
        return Integer.parseInt(tmpQ.peekLast());
    }
}