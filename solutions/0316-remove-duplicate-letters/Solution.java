class Solution {
    public String removeDuplicateLetters(String s) {
        StringBuilder ans = new StringBuilder();
        int[] c=new int[26];
        int[] o=new int[26];
        int n = s.length();
        for(int i=0;i<n;i++){
            c[(int)s.charAt(i)-'a']++;
        }
        for(int i=0;i<n;i++){
            int id =(int)s.charAt(i)-'a';
            if(o[id]>0){
                c[id]--;
                continue;
            }
            if(ans.isEmpty() || s.charAt(i)>ans.charAt(ans.length()-1)){
                c[id]--;
                o[id]++;
                ans.append(s.charAt(i));
            }
            else{
                while(!ans.isEmpty() && s.charAt(i)<ans.charAt(ans.length()-1) && c[(int)ans.charAt(ans.length()-1)-'a']>0){
                    o[(int)ans.charAt(ans.length()-1)-'a']--;
                    ans.deleteCharAt(ans.length()-1);
                }
                o[id]++;
                c[id]--;
                ans.append(s.charAt(i));
            }
        }
        return ans.toString();
    }
}