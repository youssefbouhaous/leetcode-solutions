class Solution {
    int f(String s) {
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
    public List<Integer> diffWaysToCompute(String e) {
        List<Integer> ans = new ArrayList<>();
        int n = e.length();
        Set<Character> st = new HashSet<>(List.of('-','+','*'));
        for (int i=0;i<n;i++){
            char o = e.charAt(i);
            if (st.contains(o)){
                String a = e.substring(0,i);
                String b = e.substring(i+1);
                if(!a.isEmpty() && !b.isEmpty()){
                    List<Integer> aa = diffWaysToCompute(a);
                    List<Integer> bb = diffWaysToCompute(b);
                    switch (o){
                        case '+':
                            for (int x:aa) {
                                for (int y:bb) ans.add(x+y);
                            }
                            break;
                        case '-':
                            for (int x:aa) {
                                for (int y:bb) ans.add(x-y);
                            }
                            break;
                        case '*':
                            for (int x:aa) {
                                for (int y:bb) ans.add(x*y);
                            }
                            break;
                    }
                }
            }
        }
        if(ans.isEmpty())
        ans.add(f(e));
        return ans;
    }
}