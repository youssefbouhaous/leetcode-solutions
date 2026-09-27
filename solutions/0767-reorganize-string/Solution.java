class Solution {
    public String reorganizeString(String s) {
        int[] d = new int[26];
        int n = s.length();
        for(int i=0;i<n;i++){
            int o = s.charAt(i)-'a';
            d[o]++;
            if(d[o]>(n+1)/2)return "";
        }
        StringBuilder t=new StringBuilder();
        record P(int a,char c){};
        List<P> list = new ArrayList<>();
        for(int i=0;i<26;i++){
            list.add(new P(d[i],(char)(i+'a')));
        }
        list.sort((a,b)->{
            return b.a-a.a;
        });
        while(true){
            boolean f=false;
            int oo = 0;
            for(int i=0;i<26;i++){
                P c = list.get(i);
                if(c.a>0){
                    f=true;oo++;
                    t.append(c.c);
                    list.set(i,new P(c.a-1,c.c));
                }
                if(oo>1)break;
            }
            if(!f)return t.toString();
            list.sort((a,b)->{
                return b.a-a.a;
            });
        }
    }
}