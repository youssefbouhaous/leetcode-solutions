class Solution {
    public boolean isIsomorphic(String s, String t) {
        int n = s.length();
        int m = t.length();
        if(n!=m)return false;
        Map<Character,Character> ms = new HashMap<>();
        Map<Character,Character> mt = new HashMap<>();
        for(int i=0;i<n;i++){
            char x = s.charAt(i);
            char y = t.charAt(i);
            ms.put(x,y);
            mt.put(y,x);
        }
        for(int i=0;i<n;i++){
            char x = s.charAt(i);
            char y = t.charAt(i);
            if(ms.get(x)!=y || mt.get(y)!=x)return false;
        }
        return true;
    }
}