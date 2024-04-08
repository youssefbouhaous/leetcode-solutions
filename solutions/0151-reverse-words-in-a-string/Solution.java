class Solution {
    public String reverseWords(String s) {
        String[] a=s.split(" ");
        StringBuilder ans=new StringBuilder("");
        for(int i=a.length-1;i>0;i--){
            if(!a[i].equals(""))
            ans.append(a[i]).append(" ");
        }
        ans.append(a[0]);
        return String.valueOf(ans).strip();
    }
}