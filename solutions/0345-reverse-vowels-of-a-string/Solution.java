class Solution {
    public String reverseVowels(String s) {
        char[] st = {'a', 'e', 'i', 'o', 'u'};
        List<Character> a = new ArrayList<>();
        for(int j = 0;j<s.length();j++){
            char o = Character.toLowerCase(s.charAt(j));
            for(int i=0;i<5;i++){
                if(o == st[i]){
                    a.add(s.charAt(j));
                    break;
                }
            }
        }
        Collections.reverse(a);
        StringBuilder ans = new StringBuilder(s);
        int id = 0;
        for(int i = 0;i<s.length();i++){
            for(int j=0;j<5;j++){
                if(Character.toLowerCase(ans.charAt(i)) == st[j]){
                    ans.setCharAt(i,a.get(id++));
                    break;     
                }
            }
        }
        return ans.toString();
    }
}