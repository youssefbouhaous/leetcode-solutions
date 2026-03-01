class Solution {
    public int[] get(Deque<Integer> stack){
        int a = (stack.peek());
        stack.pop();
        int b = (stack.peek());
        stack.pop();
        return new int[]{b,a};
    }
    public int evalRPN(String[] tokens) {
        Deque<Integer> stack = new ArrayDeque<>();
        int[] tmp;
        for(String s: tokens){
            switch(s){
                case "+" :
                    tmp = get(stack);
                    stack.push((tmp[0]+tmp[1]));
                    break;
                case "-" :
                    tmp = get(stack);
                    stack.push((tmp[0]-tmp[1]));
                    break;
                case "*" :
                    tmp = get(stack);
                    stack.push((tmp[0]*tmp[1]));
                    break;
                case "/" :
                    tmp = get(stack);
                    stack.push((tmp[0]/tmp[1]));
                    break;
                default:
                    stack.push(Integer.parseInt(s));
            }
        }
        return stack.peek();
    }
}