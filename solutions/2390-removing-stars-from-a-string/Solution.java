class Solution {
    public String removeStars(String s) {
        StringBuilder a = new StringBuilder("");
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s.charAt(i)=='*'){
                if(!a.isEmpty())a.deleteCharAt(a.length()-1);
            }else{
                a.append(s.charAt(i));
            }
        }
        return a.toString();
    }
}