class Solution {
    public boolean isIsomorphic(String s, String t) {
        int n=s.length();
        int m=t.length();
        if(n!=m)return false;
        int[] ms = new int[128];
        int[] mt = new int[128];
        Arrays.fill(ms,-1);
        Arrays.fill(mt,-1);
        for(int i=0;i<n;i++){
            int a=s.charAt(i);
            int b=t.charAt(i);
            if((ms[a]==-1&&mt[b]==-1) || (ms[a]!=-1 && a==mt[b] && b==ms[a])){
                ms[a]=b;
                mt[b]=a;
            }else{
                return false;
            }
        }
        return true;
    }
}