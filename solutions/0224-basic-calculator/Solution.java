class Solution {
    public int calculate(String s) {
        Stack<String> stack = new Stack<>();
        Set<Character> setOp= new HashSet<>(List.of('+','-'));
        int i=0;
        int n = s.length();
        while (i<n){
            char o =s.charAt(i);
            if(o==' '){i++;continue;}
            if(o!=')'){
                if(Character.isDigit(o)){
                    StringBuilder tmp = new StringBuilder();
                    while (i<n && Character.isDigit(o)){
                        tmp.append(o);
                        i++;
                        if(i<n)
                        o=s.charAt(i);
                    }
                    stack.add(tmp.toString());
                }
                else{
                    stack.add(o+"");
                    i++;
                }
            }
            else{
                i++;
                Deque<String> q = new ArrayDeque<>();
                while (!stack.peek().equals("(")){
                    q.addFirst(stack.pop());
                }
                stack.pop();
                while(q.size()>1){
                    String a = q.pollFirst();
                    String b = q.pollFirst();
                    if(setOp.contains(a.charAt(0)) && a.length()==1){
                        if(b.charAt(0)!='-'){
                            q.addFirst("-"+b);
                        }else
                        q.addFirst(-Integer.parseInt(b)+"");
                        continue;
                    }
                    String c = q.pollFirst();
                    if(b.equals("-")){
                        int intA = Integer.parseInt(a);
                        int intB = Integer.parseInt(c);
                        q.addFirst(intA-intB+"");
                    }else{
                        int intA = Integer.parseInt(a);
                        int intB = Integer.parseInt(c);
                        q.addFirst(intA+intB+"");
                    }
                }
                stack.push(q.peek());
            }
        }
        Deque<String> q = new ArrayDeque<>();
        while (!stack.isEmpty()){
            q.addFirst(stack.pop());
        }
        while(q.size()>1){
            String a = q.pollFirst();
            String b = q.pollFirst();
            if(setOp.contains(a.charAt(0)) && a.length()==1){
                if(b.charAt(0)!='-'){
                    q.addFirst("-"+b);
                }else
                q.addFirst(-Integer.parseInt(b)+"");
                continue;
            }
            String c = q.pollFirst();
            if(b.equals("-")){
                int intA = Integer.parseInt(a);
                int intB = Integer.parseInt(c);
                q.addFirst(intA-intB+"");
            }else{
                int intA = Integer.parseInt(a);
                int intB = Integer.parseInt(c);
                q.addFirst(intA+intB+"");
            }
        }
        return Integer.parseInt(q.peekLast());
    }
}