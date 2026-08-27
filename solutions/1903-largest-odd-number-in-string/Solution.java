class Solution {
    public String largestOddNumber(String num) {
        StringBuilder ans = new StringBuilder();
        int n = num.length();
        char[] arr = num.toCharArray();
        for(int i=n-1;i>-1;i--){
            if(ans.isEmpty() && (num.charAt(i)-'0')%2==1){
                ans.append(num.charAt(i));
            }else if(!ans.isEmpty()){
                ans.append(num.charAt(i));
            }
        }
        return ans.reverse().toString();
    }
}