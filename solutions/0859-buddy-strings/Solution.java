class Solution {
    public boolean buddyStrings(String s, String goal) {
        int n = s.length();
        int m=goal.length();
        if(n!=m)return false;
        int a = -1;
        int b = -1;
        char[] sc=s.toCharArray();
        int[] cnt = new int[26];
        for(int i=0;i<n;i++){
            if(sc[i]!=goal.charAt(i)){
                if(a!=-1 && b!=-1)return false;
                else if(a==-1)a=i;
                else if(b==-1)b=i;
            }
            cnt[sc[i]-'a']++;
        }
        if(a==-1 && b==-1){
            for(int i=0;i<26;i++){
                if(cnt[i]>1)return true;
            }
            return false;
        }else if(b==-1)return false;
        char t=sc[a];
        sc[a]=sc[b];
        sc[b]=t;
        return goal.equals(new String(sc));
    }
}