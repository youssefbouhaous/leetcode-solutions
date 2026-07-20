class Solution {
    public int lengthOfLastWord(String s) {
        int c=0;
        int l=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s.charAt(i)!=' ')c++;
            else{
                if(c!=0)l=c;
                c=0;
            }
        }
        if(c!=0)l=c;
        return l;
    }
}