class Solution {
    public boolean repeatedSubstringPattern(String s) {
        int n = s.length();
        List<Integer> ans = new ArrayList<>();
        for(int i = 1 ;i<n;i++){
            if(n%i==0)ans.add(i);
        }
        for(Integer i : ans){
            StringBuilder tmp = new StringBuilder();
            while(tmp.length()<n){
                tmp.append(s.substring(0,i));
            }
            if(tmp.toString().equals(s))return true;
        }
        return false;
    }
}