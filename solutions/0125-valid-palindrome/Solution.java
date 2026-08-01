class Solution {
    public boolean isPalindrome(String s) {
        StringBuilder ans = new StringBuilder();
        int n = s.length();
        for(int i=0;i<n;i++){
            char o = s.charAt(i);
            if(Character.isLetter(o)){
                ans.append(Character.toLowerCase(o));
            }
            if(Character.isDigit(o)){
                ans.append(o);
            }
        }
        return ans.toString().equals(ans.reverse().toString());
    }
}