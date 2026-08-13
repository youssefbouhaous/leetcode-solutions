class Solution {
    public int scoreOfParentheses(String s) {
        //Stack<Integer> st = new Stack<>();
        //"80"
        Stack<Integer> sc = new Stack<>();
        int n = s.length();
        for(int i=0;i<n;i++){
            char o = s.charAt(i);
            if(o=='('){
                sc.push(0);
            }else{
                int res = 0;
                //"(40)"
                while(sc.peek()!=0){    
                    res += sc.pop();
                }
                sc.pop();
                if(res==0)res=1;
                else res=res*2;
                sc.push(res);
            }
        }
        int ans=0;
        while(!sc.isEmpty()){
            int o = sc.peek();        
            ans+=sc.pop();
        }
        return ans;
    }
}