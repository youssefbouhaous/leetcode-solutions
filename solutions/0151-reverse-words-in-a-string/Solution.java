class Solution {
    public String reverseWords(String s) {
       List<String> a = Arrays.asList(s.split(" "));
       for(String x:a)System.out.print(x+' ');
       Collections.reverse(a);
       StringBuilder ans = new StringBuilder();
       for(int i=0;i<a.size()-1;i++){
            if(!a.get(i).isBlank())
            ans.append(a.get(i).strip()+' ');
       }
       if(!a.get(a.size()-1).isBlank())
       ans.append(a.get(a.size()-1).strip());
       return ans.toString().strip();
    }
}