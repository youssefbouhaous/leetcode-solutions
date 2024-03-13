class Solution {
    public boolean canConstruct(String mm, String r) {
        Map<Character,Integer>m=new HashMap<>();
        for(int i=0;i<r.length();i++){
            if(!m.containsKey(r.charAt(i))){
                m.put(r.charAt(i),1);
            }
            else{
                m.put(r.charAt(i),m.get(r.charAt(i))+1);
            }
        }
        for(int i=0;i<mm.length();i++){
            if(!m.containsKey(mm.charAt(i)) || m.get(mm.charAt(i))==0){
                return false;
            }
            else{
                m.put(mm.charAt(i),m.get(mm.charAt(i))-1);
            }
        }
        return true;
    }
}