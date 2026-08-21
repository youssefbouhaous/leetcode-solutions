class Solution {
    public boolean isIsomorphic(String s, String t) {
        int n = s.length();
        int m = t.length();
        if(n!=m)return false;
        int[] ms = new int[1000];
        int[] mt = new int[1000];
        Arrays.fill(ms,-1);
        Arrays.fill(mt,-1);
        for(int i=0;i<n;i++){
            int a=s.charAt(i);
            int b=t.charAt(i);
            if(ms[a]==b || (ms[a]==-1 && mt[b]==-1)){
                if(mt[b]!=-1 && mt[b]!=a)return false;
                ms[a]=b;
                mt[b]=a;
            }else{
                return false;
            }
        }
        return true;
    }
}