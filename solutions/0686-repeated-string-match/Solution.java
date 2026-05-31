class Solution {
    public int repeatedStringMatch(String a, String b) {
        int n = a.length();
        int m = b.length();
        if(a.contains(b))return 1;
        StringBuilder t = new StringBuilder();
        int i = 0;
        while(t.length()<=n+m){
            if(t.toString().contains(b))return i;
            i++;
            t.append(a);
        }
        if(t.toString().contains(b))return i;
        return -1;
    }
}