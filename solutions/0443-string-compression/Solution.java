class Solution {
    public int compress(char[] chars) {
        int n = chars.length;
        if(n==1)return 1;
        int c = 1;
        List<String> s = new ArrayList<>();
        int i = 1;
        while(i<n){
            if(chars[i]!=chars[i-1]){
                s.add(""+chars[i-1]);
                if(c!=1)
                s.add(""+c);
                c=1;
            }
            else{
                c++;
            }
            i++;
        }
        s.add(""+chars[i-1]);
        if(c!=1)
        s.add(""+c);
        int id = 0;
        for(String x : s){
            for(int j=0;j<x.length();j++){
                System.out.println(id);
                System.out.println(x);
                chars[id++] = x.charAt(j);
            }
        }
        return id;
    }
}