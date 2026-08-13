class Solution {
    public int calculate(String s) {
        int ans = 0;
        int pre = 0;
        char op = '+';
        int n = s.length();
        int i = 0;
        while(i<n){
            char o = s.charAt(i);
            if(o==' '){i++;continue;}
            if(Character.isDigit(o)){
                int t = 0;
                while(i<n && Character.isDigit(s.charAt(i))){
                    t=t*10+(s.charAt(i++)-'0');
                }
                i--;
                switch(op){
                    case '+':
                    ans+=t;
                    pre=t;break;
                    case '-':
                    ans-=t;pre=-t;break;
                    case '*':
                    ans=ans-pre+pre*t;pre=pre*t;break;
                    case '/':
                    ans=ans-pre+pre/t;pre=pre/t;break;
                }
            }else{
                op=o;
            }
            i++;
        }
        return ans;
    }
}