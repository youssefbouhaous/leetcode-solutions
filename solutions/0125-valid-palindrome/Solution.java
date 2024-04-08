class Solution {
    public boolean isPalindrome(String s) {
       
        StringBuilder ss=new StringBuilder("");
        for(int i=0;i<s.length();i++){
            char x=s.charAt(i);
            if(('a'<=x && x<='z') || ('A'<=x && x<='Z')){
                ss.append(Character.toLowerCase(x));
            }
            if('0'<=x && x<='9'){
                ss.append(x);
            }
        }
         int l=0;
        int r=ss.length()-1;
        while(l<r){
            if(ss.charAt(l)!=ss.charAt(r)){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
}