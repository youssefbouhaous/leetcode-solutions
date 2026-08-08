class Solution {

    public boolean isPalindrome(String s,int l,int r){
        if(l==r)return true;
        while(l<r){
            char a = s.charAt(l++);
            char b = s.charAt(r--);
            if(a!=b)return false;
        }
        return true;
    }
    public boolean validPalindrome(String s) {
        int n = s.length();
        int l = 0;
        int r = n-1;
        int c =0;
        while(l<r){
            char a = s.charAt(l);
            char b = s.charAt(r);
            if(a==b){
                l++;r--;
            }
            else{
                if(a==s.charAt(r-1) && isPalindrome(s,l,r-1)){
                    r--;
                }else if(b==s.charAt(l+1) && isPalindrome(s,l+1,r)){
                    l++;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
}