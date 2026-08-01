class Solution {
    public boolean isIsomorphic(String s, String t) {
        Map<Character,Character> mps = new HashMap<>();
        Map<Character,Character> mpt = new HashMap<>();
        int n = s.length();
        for(int i=0;i<n;i++){
            char a = s.charAt(i);
            char b = t.charAt(i);
            if(mps.get(b)==null){
                if(mpt.get(a)!=null && mpt.get(a)!=b)return false;
                mps.put(b,a);
                mpt.put(a,b);
            }
            else if(mps.get(b)!=a){
                return false;
            }
            
        }
        return true;
    }
}